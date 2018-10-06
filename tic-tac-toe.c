#include <stdio.h>

#include <stdlib.h>

int wPlayer();
void wBot();
void check();
void Print(int x, char xo);


char pos[12];									//store position

//include return in main for win


int main(int argc, char const *argv[])
{
	int ch=0;
	while(ch!=3)
	{
		int i=1;
		while (i<=9){
		pos[i]='_';
		if(i>6)
			pos[i]=' ';
		i++;
		}

		printf("choose\n\n \t1: with Bot\t 2: With 2nd player\n\n\n");

		printf("Grids are numbered as \n\t_1_|_2_|_3_\n\t_4_|_5_|_6_\n\t 7 | 8 | 9 \n\n\n");
		
		scanf("%d",&ch);
		char c;
		while((c=getchar())!='\n'&&c!=EOF);
		int win;
		switch(ch){
			case 1:
			//											Bot();
			break;
			case 2:
			win=wPlayer();
			break;
			default: 
			printf("Wrong choice\n");
		}
		if(win==0){
			printf("O wins\n");
		}
		else if(win==1){
			printf("X wins\n");
		}
		else{
			printf("Wrong intput please try again\n");
		}
	}

	return 0;
}

void Print(int x,char xo){
	
	
	
	pos[x]=xo;
	printf("\t_%c_|_%c_|_%c_\n\t_%c_|_%c_|_%c_\n\t %c | %c | %c ",pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],pos[8],pos[9]);

	
	
}

int wPlayer(){
	int win=-1;						//recards if there's been a win
	int recx=0;						//record where the X has been stored
	int reco=0;						//record where the O has been stored
	int ch;							//takes user choice and stores
	int rec=0;						//checking doubleing of choice input

	int conf=0;						//stores confirmation for index repeat




	int temp;					//for da checks

	Print(9,' ');					//prints blank tictactoe
	
	while(win==-1)
	{
		

		printf("\nGo Player X\n");

		conf=0;

		temp=rec;

		while(!conf)
		{	
			conf++;
			scanf("%d",&ch);

			temp=rec;

			while(temp!=0&&ch>=1&&ch<=9){				//checks for repeat
				if (temp%10==ch){
					printf("wrong choice\n");


					conf--;				//if repeated choice, conf=0 and loop runs again
					
					break;
				}



				temp=temp/10;
			}
		}

		rec=rec*10+ch;					//stores all coices
		
		Print(ch,'X');					//calls function to print


		if(ch>recx%10)
		{
			recx=recx*10+ch;			//stores X position acocridng to ascending index
		}

		else if(ch<recx%10)
		{
			recx=ch*10+recx;
		}
	
	
		printf("\nGo Player O\n");


		

		temp=rec;
		conf=0;

		while(conf==0)
		{	
			conf++;
			scanf("%d",&ch);
			temp=rec;

			while(temp!=0&&ch>=1&&ch<=9){				//checks for repeat
				if (temp%10==ch){
					printf("wrong choice\n");


					conf--;				//if repeated choice, conf=0 and loop runs again

					break;
				}


				temp=temp/10;
			}
		}

		


		rec=rec*10+ch;
		
		Print(ch,'O');

		if(ch>reco%10){
			reco=reco*10+ch;			//stores O position acocridng to ascending index
		}

		else if(ch<reco%10){
			reco=ch*10+reco;
		}

		switch(recx){					//checks X win
			case 123:
			case 456:
			case 789:
			case 159:
			case 357:
			return 1;
			break;
		}
		switch(reco){					//checks O win
			case 123:
			case 456:
			case 789:
			case 159:
			case 357:
			return 0;
			break;
		}

		


	}
}