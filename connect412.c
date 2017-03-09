// CONNECT FOUR
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//hi there
int top[]={6,6,6,6,6,6,6},count;
char a[7][7];

void menu();

void display(int k)		//to display the grid
{
	int i,j,u=0;
	system("clear");
	printf("\n\t\t\t    FOUR IN A ROW ");
	printf("\n\t\t\t    ==== == = === \n\t\t");
	for(i=0; i<7; ++i)
	printf("   %d ",i);
	printf("\n");
	if(k<4)
	{
		for(i=0; i<7; ++i)
		{
			printf("\t\t|");
			for(j=0; j<7; ++j)
			{
				printf("| %c |",a[i][j]);
			}
			printf("|\n");
		}
	}
	if(k==4)		//for showing the winning combination(blink)
	{
		while(u<=10)		
		{
			system("clear");
			printf("\n\t\t\t    FOUR IN A ROW ");
			printf("\n\t\t\t    ==== == = === \n\t\t");
			for(i=0; i<7; ++i)
			printf("   %d ",i);
			printf("\n");

			if(u%2==0)
			{
				for(i=0; i<7; ++i)
				{
					printf("\t\t|");
					for(j=0; j<7; ++j)
					{
						printf("| %c |",a[i][j]);
					}
					printf("|\n");
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
							printf("| %c |",a[i][j]);
						}
						else
						{
							printf("|   |");
						}
					}
					printf("|\n");
				}
			}
			system("sleep 0.2");
			u++;
		}
	}
}

void put(int n, char x)		//to put the coin
{
	a[top[n]][n]=x;
	top[n]--;
}


void init()		//to initialise the grid for new game
{
	int i,j;
	for(i=0; i<7; ++i)
	{
		top[i]=6;
		for(j=0; j<7; ++j)
		{
			a[i][j]=' ';
		}
	}
}

int vert(int x, int y, char z)		//to check vertically if there is a winning combination
{
	int i=x,j=y,k=0,u;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i++;
		k++;
	}
	i=x-1;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i--;
		k++;
	}
	i=x;j=y;
	if(k==4)
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			i++;
		}
		i=x-1;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			i--;
		}
	}
	return k;
}

int horz(int x, int y, char z)		//to check horizontally if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		j++;
		k++;
	}
	j=y-1;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		j--;
		k++;
	}

	i=x;j=y;
	if(k==4)
	{	
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			j++;
		}
		j=y-1;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			j--;
		}
	}		
	return k;
	
}

int left(int x, int y, char z)		//to check the left diagonal if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i++;
		j++;
		k++;
	}
	i=x-1;
	j=y-1;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i--;
		j--;
		k++;
	}
	i=x;j=y;
	if(k==4)
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			i++;
			j++;
		}
		i=x-1;
		j=y-1;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			i--;
			j--;
		}
	}
	return k;
}

int right(int x, int y, char z)		//to check right diagonal if there is a winning combination
{
	int i=x,j=y,k=0;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i++;
		j--;
		k++;
	}
	i=x-1;
	j=y+1;
	while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
	{
		i--;
		j++;
		k++;
	}
	i=x;j=y;	
	if(k==4)
	{
		count=4;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';			
			i++;
			j--;
		}
		i=x-1;
		j=y+1;
		while(a[i][j]==z&&(i>=0 && i<=6)&&(j>=0 && j<=6))
		{
			a[i][j]='#';
			i--;
			j++;
		}
	}
	return k;
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

