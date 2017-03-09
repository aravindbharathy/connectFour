// CONNECT FOUR
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int top[]={6,6,6,6,6,6,6},count; //initialize array to hold values of every spot in top row
char a[7][7]; //7x7 matrix initialized to use for sweeping 

void menu(); //calls menu function at the end of this page

void display(int k)		//to display the grid
{
	int i,j,u=0;   
	system("clear");
	printf("\n\t\t\t    FOUR IN A ROW ");
	printf("\n\t\t\t    ==== == = === \n\t\t");
	for(i=0; i<7; ++i)    //initiates loop for making grid
	printf("   %d ",i);   //creates 7 spaces
	printf("\n");
	if(k<4)  // k represents the number of tiles in a row
	{
		for(i=0; i<7; ++i) 
		{
			printf("\t\t|");
			for(j=0; j<7; ++j) //continues filling up the grid tabs
			{
				printf("| %c |",a[i][j]);  //updates grid
			}
			printf("|\n");
		}
	}
	if(k==4)		//for showing the winning combination(blink)
	{
		while(u<=10) //there should be at most 10 user turns
		{
			system("clear"); //remove the grid
			printf("\n\t\t\t    FOUR IN A ROW "); //display win message
			printf("\n\t\t\t    ==== == = === \n\t\t");
			for(i=0; i<7; ++i)
			printf("   %d ",i); //create 7 new spaces 
			printf("\n");

			if(u%2==0) //cond. statement where u represents every other user’s turn
			{
				for(i=0; i<7; ++i) //iterate through all rows
				{
					printf("\t\t|");
					for(j=0; j<7; ++j) //iterate through all columns
					{
						printf("| %c |",a[i][j]);  //display board contents
					}
					printf("|\n"); //start printing next row 
				}

				
			}
			else
			{
				for(i=0; i<7; ++i)
				{
					printf("\t\t|");
					for(j=0; j<7; ++j)
					{
						if(a[i][j]!='#')
						{
							printf("| %c |",a[i][j]); //display contents of chars stored in ‘a’
						}
						else
						{
							printf("|   |"); //displays space if a piece isn’t placed
						}
					}
					printf("|\n");
				}
			}
			system("sleep 0.2");
			u++;  //incr. user’s turn variable u to indicate next turn
		}
	}
}

void put(int n, char x)		//to put the coin
{
	a[top[n]][n]=x;  //checks the state of the top row, and stores value to x
	top[n]--;  // if a coin is added, the top row’s nth column’s decreases
}


void init()		//to initialize the grid for new game
{
	int i,j;
	for(i=0; i<7; ++i)
	{
		top[i]=6;  //top row resets values so it doesn’t hold any pieces
		for(j=0; j<7; ++j)
		{
			a[i][j]=' ';  //chars held by a are assigned matrix values from [0,0] to [7,7]
		}
	}
}

int vert(int x, int y, char z)		//to check vertically if there is a winning combination
{
	int i=x,j=y,k=0,u;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6)) //check through every char as you sweep through every matrix entry
	{
		i++; 			//look through every column by going to next one
		k++; 			//k = 1 indicates one piece, k = 4 means there are 4 consecutive pieces
	}
	i=x-1; 				//initialize i to hold previous value of x
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6)) //check previous entry’s char in similar fashion as before
	{
		i--; 			//reduce column number
		k++; 			//adds value to k if the previous value is valid
	}
	i=x;j=y;
	if(k==4)  	//cond statement for when there are 4 consecutive pieces in a column
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6)) //while iterating through all rows and columns when they’re under 7
		{
			a[i][j]='#';  // add # sign to change state of tile to indicate win
			i++;
		}
		i=x-1;//initialize i to hold previous value of x, instead of current
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';   // add # to indicate location of previous winning tile’s position
			i--;
		}
	}
	return k;
}

int horz(int x, int y, char z)		//to check horizontally if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))  //check through every char as you sweep through every matrix entry
	{
		j++;			//look through every row by going to next one
		k++;			//k = 1 indicates one piece, k = 4 means there are 4 consecutive pieces
	}
	j=y-1;   			//initialize j to hold previous value of y
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		j--;			//look at previous row to ensure valid piece
		k++;			// adds value to k if the previous entry is valid
	}

	i=x;j=y;
	if(k==4)    //cond statement for when there are 4 consecutive pieces in a row
	{	
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))   //check through every char a 
		{
			a[i][j]='#';	//indicate winning piece’s state by changing it to #
			j++;		//check next row
		}
		j=y-1;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6)) //checking thorough previous values of char in every row
		{
			a[i][j]='#';     //indicate previous piece’s state by changing it to #
			j--;		//reduce value of row
		}
	}		
	return k;  //is there a winner? yes, if k = 4
	
}

int left(int x, int y, char z)		//to check the left diagonal if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))  //increment through all values in 7x7 matrix
	{
		i++;    	//indicate that column variable is a incr.
		j++;		//row values needs to incr. to make diagonal 
		k++;		//add another piece value to k if the previous entry is valid
	}
	i=x-1;			// get state of previous columns
	j=y-1;			// get state of previous rows
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))  //check all characters in 7x7 matrix
	{
		i--;		//reduce value of column
		j--;		//row reduced to continue checking diagonal
		k++;		//adds value to k if the previous value is valid
	}
	i=x;j=y;
	if(k==4)    //cond statement for when there are 4 consecutive pieces in a left diagonal
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))   //increment through all characters to look for winning combo
		{
			a[i][j]='#';    //when you find a valid entry, change to #
			i++;		//check next column’s value
			j++;		//check next row 
		}
		i=x-1;   		//set i to previous x values
		j=y-1;			//set j to prev y 
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))   //check all previous characters
		{
			a[i][j]='#';	//if valid, change entry to #
			i--;		//check previous column
			j--;		//check previous row
		}
	}
	return k; //check if value of k is 4 yet
}

int right(int x, int y, char z)		//to check right diagonal if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6)) //for checking right diagonals, follow same format EXCEPT:
	{
		i++;			//check values of columns in ascending order
		j--;			//check values of row in descending order
		k++;
	}
	i=x-1;		//get previous values
	j=y+1;		//get next values
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i--;			//do inverse of algorithm above, follow symmetry from before
		j++;
		k++;
	}
	i=x;j=y;	
	if(k==4)		//cond statement asserted when there are 4 consecutive pieces in a right diagonal 
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';		//replace winning pieces by #	
			i++;			//increment column to replace next piece
			j--;			//decrement row to continue diagonal replacement
		}
		i=x-1;			//previous value check for column
		j=y+1;			//next value check for row
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';     //replace winning piece’s value
			i--;		//continue checking previous column values
			j++;		//continue looking for diagonal
		}
	}
	return k;  //checks when k is anywhere from 0 to 4
}

int win(int x)		//to display the winning counter
{
	char z=a[top[x]+1][x];
	if(left(top[x]+1,x,a[top[x]+1][x])==4)
	{
		display(4);
		printf("\n\t\t\t      %c WINS!!!\n",z);
		return 1;
	}
	else if(right(top[x]+1,x,a[top[x]+1][x])==4)
	{
		display(4);
		printf("\n\t\t\t      %c WINS!!!\n",z);
		return 1;
	}
	else if(vert(top[x]+1,x,a[top[x]+1][x])==4)
	{
		display(4);
		printf("\n\t\t\t      %c WINS!!!\n",z);
		return 1;
	}
	else if(horz(top[x]+1,x,a[top[x]+1][x])==4)
	{
		display(4);
		printf("\n\t\t\t      %c WINS!!!\n",z);
		return 1;
	}
	else
	{
		return 0;
	}
}

	
void start()		//game play
{
	int d=0,n,v;
	init();
	while(d<49)
	{
		display(0);
		printf("\nColumn: ");
		scanf("%d",&n);
		
		if((n>=0 && n<=6) && (top[n]>=0))
		{
			if(d%2==0)
			{
				put(n,'X');
			}
			else
			{
				put(n,'O');
			}
			d++;
		}
		else
		{ printf("\n Invalid Input!!!\n"); }
		if(win(n)) { break; }
	}

	printf("\n\t\t\t |m|_ GaMe OvEr _|m| \n\n\n");
	if (count==4)
	{
		FILE *ptr=fopen("score.txt","a+");
		char player[30];
		printf("\n Enter Winner's Name: ");
		scanf("%s",player);
		strcat(player,"\n");
		fputs(player, ptr);
		fclose(ptr);
	}
	else 
		printf("\n\t\t\t Game Draw!!!\n");
	system("sleep 3");
	menu();
}

void credits()		//display animated credits
{
	system("clear");
	printf("\n Created By: D.BRAGHADEESH CSE11209\n");
}

void play()		//instruction file
{
	system("clear");
	char x;
	FILE *ptr;
	ptr=fopen("play.txt","r");
	printf("\n\t\t\t HOW TO PLAY");
	printf("\n\t\t\t --- -- ----\n\n");
	while(!feof(ptr))
	{
		printf("%c",fgetc(ptr));
	}
	printf("\n\n Return Any Key For Main Menu");
	scanf(" %c",&x);
	menu();
}

void high()		//hall of fame file
{
	system("clear");
	char x;
	FILE *ptr;
	ptr=fopen("score.txt","r");
	printf("\n\t\t\t HALL OF FAME");
	printf("\n\t\t\t ~~~~ ~~ ~~~~\n\n");
	while(!feof(ptr))
	{
		printf("%c",fgetc(ptr));
	}
	printf("\n\n Return Any Key For Main Menu\n");
	scanf(" %c",&x);
	system("clear");
	menu();
}
main()
{
	int u;
	char s[]="FOUR IN A ROW";
	for(u=0;u<=strlen(s);u++)
	{
		printf("\t\t\t%.*s\n",u,s);
		system("sleep 0.5");		
		system("clear");
		
	}
	menu();
}


void menu()		//menu options
{
	int i;
	system("clear");
	printf("\n\t\t\tFOUR IN A ROW");
	printf("\n\t\t\t==== == = ===");
	printf("\n1.Start Game\n2.How to Play\n3.High Scores\n4.Exit\nEnter your choice:");
	scanf("%d",&i);
	switch(i)
	{
		case 1: init(); start();break;
		case 2: play(); break;
		case 3: high(); break;
		case 4: credits(); exit(0); break;
		default: printf(" \nInvalid Input!\n"); system("sleep 2");
				menu();
	}
}

