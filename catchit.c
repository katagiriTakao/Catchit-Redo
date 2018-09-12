#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int valorbarrera,valorbarrera2,valorflecha,healthpoint=5,score=0;


char mapa[27][87] = {//27filas y 75 columnas.
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXX$$$$XXXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXX$$$$$$XXX$$$$$$XXXXX$$$$$$$XX$$$$$$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXXXXXXX$$XXXX$$XXXXXX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXX$$$$$$$XXXX$$XXXXXX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXX$$XXX$$XXXX$$XXXX$$XX$$XX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXX$$$$XXXXXX$$$$$$$XXXXX$$$$XXXX$$$$$$$XX$$XXXX$$XXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",    
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$$$$$XX$$$$$$$$XX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",   
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$$$$$XXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
};
char mapa2[27][87] = {//27filas y 75 columnas.
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
          "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXX$$$$XXXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXX$$$$$$XXX$$$$$$XXXXX$$$$$$$XX$$$$$$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXXXXXXX$$XXXX$$XXXXXX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXXXXXXXX$$$$$$$XXXX$$XXXXXX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXX$$XXX$$XXX$$XXXX$$XXXX$$XX$$XX$$XXXXXXXX$$XXXX$$XXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXX$$$$XXXXXX$$$$$$$XXXXX$$$$XXXX$$$$$$$XX$$XXXX$$XXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",    
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$$$$$XX$$$$$$$$XX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",   
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$XXXXXXX$$XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX$$$$$$XXXXX$$XXXXX$$XXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
     "      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  ",
};





void menu()
{
 char menu,text;
 textcolor(GREEN);
 gotoxy(30,12);
 cprintf("INSTRUCTIONS: PRESS_1 ");
 gotoxy(30,14);
 cprintf("PLAY GAME: PRESS_2");
 while(!kbhit)
 Beep (440,100);Sleep(300);
        Beep (349,100);Sleep(100);
        Beep (392,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
menu=getch();
if (menu=='1')
{
     clrscr();
     gotoxy(1,1);         
	FILE*read;
	read=fopen("C:\\Users\\PREPA 6\\Desktop\\instrucciones.txt","r");
	
    if(read==NULL)
		printf("ERROR: NO INSTRUCCIONES FILE\n");
		
	else
	{
		while (feof(read)==0)
		{
			text=fgetc(read);
			printf("%c",text);
            			
		}
		getch();
		clrscr();
	}
fclose(read);
}          
 if (menu=='2')
 {
    clrscr();
    printf("go");
    Sleep(300);
    clrscr();
}
 return;
 
 }

/////////////////////////////////////
void pintar_mapa()
{
     int i,j;
     for(i = 0 ; i < 75 ; i++){
         for(j = 0 ; j < 27 ; j++){
               gotoxy(i,j);
               
               if(mapa[j][i] == '|') {printf("%c",179);}
               if(mapa[j][i] == '_') {printf("%c",95);}
               if(mapa[j][i] == '<') {printf("%c",60);}
               if(mapa[j][i] == '>') {printf("%c",62);}
               if(mapa[j][i] == '/') {printf("%c",47);}
               if(mapa[j][i] == 92) {printf("%c",92);}
               if(mapa[j][i] == 'X') {printf("%c",46);}
               if(mapa[j][i] == '\0') {printf("%c",'\0');}
               if(mapa[j][i] == 36) {printf("%c",223);}
                         }
                         }
Sleep(700);
 for(i = 0 ; i < 75 ; i++){
         for(j = 0 ; j< 27 ; j++){
               gotoxy(i,j);
               if(mapa2[j][i] == '|') {printf("%c",179);}
               if(mapa2[j][i] == '_') {printf("%c",95);}
               if(mapa2[j][i] == '<') {printf("%c",60);}
               if(mapa2[j][i] == '>') {printf("%c",62);}
               if(mapa2[j][i] == '/') {printf("%c",47);}
               if(mapa2[j][i] == 92) {printf("%c",92);}
               if(mapa2[j][i] == 'X') {printf("%c",58);}
               if(mapa2[j][i] == '\0') {printf("%c",'\0');}     
         }
     }
 }

void velocideee(int *speed)
{
     if (score>=0){
      *speed=100;
      if (score>=20)
      *speed=80;
      if (score>=40)
      *speed=60;
      if (score>=50)
      *speed=50;
      }
}

void limpiar()
{
	gotoxy(40,13);
	printf("%c",126);
	gotoxy(37,15);
	printf("%c",126);
	gotoxy(43,15);
	printf("%c",126);
	gotoxy(40,17);
	printf("%c",126);
	return;
}



int comparar(int e)
{
int rando;  
     if (valorflecha==valorbarrera2)          
          {
               score++;
               rando=rand()%10+1;
               textcolor(GREEN);
               gotoxy(37,4);
               cprintf("GOOD");
               Beep(700, 200);
               }
     else         
           {
                 if(e==10)
                {
                if (healthpoint<9)
                {            
                healthpoint++;
                rando=rand()%10+1;
                textcolor(LIGHTRED);
                gotoxy(37,4);
                cprintf("%c%c%c%c",3,3,3,3);
                Beep(700, 200); 
                }
                else
                {
                score++;
                rando=rand()%10+1;
                textcolor(LIGHTRED);
                gotoxy(37,4);
                cprintf("%c%c%c%c",3,3,3,3);
                Beep(700, 200);            
                }
                } 
                else
                {
                healthpoint--;
                rando=rand()%10+1;
                textcolor(RED);
                gotoxy(37,4);
                cprintf("MISS"); 
                Beep(300, 200);                    
                }
                }       
     
     return rando;
          }                

void intro()
{
      Beep(660, 1000);
      Beep(528, 1000);
      Beep(594, 1000);
      Beep(495, 1000);
      Beep(528, 1000);
      Beep(440, 1000);
      Beep(419, 1000);
return;
}


void flujo_de_flechas (void)
{
int a,b=5,c=b-1,j=30,k=j-1,l=50,m=l+1,o=24,p=o+1,aleatorio=0,velocidA=100;
do
{
  if (!kbhit())//flechas
     {
		 if(aleatorio==3||aleatorio==0||aleatorio==5)
					{//arriba
						textcolor(CYAN);
                        Sleep(velocidA);
					    gotoxy(40,b);
					    putchar('v');
					    b++;
					    gotoxy(40,c);
					    putchar('\0');
					    c++;
					    gotoxy(6,6);
					    printf("HEALTH: %i",healthpoint);
				        gotoxy(6,7);
			    	    printf("SCORE: %i",score);
					    if(b==13)
					    	{
					        b=5;
					        valorflecha=4;
					        valorbarrera2=valorbarrera;
					        aleatorio=comparar(aleatorio);
					        velocideee(&velocidA);
					        }
					    else
					        valorflecha=valorbarrera;    
					        if(c==13)
					        c=b-1;
					}
		 if(aleatorio==10)
					{//corazon
						textcolor(LIGHTRED);
                        Sleep(velocidA);
					    gotoxy(40,b);
					    putchar(03);
					    b++;
					    gotoxy(40,c);
					    putchar('\0');
					    c++;
					    if(b==13)
					    	{
					        b=5;
					        valorflecha=0;
					        valorbarrera2=valorbarrera;
					        aleatorio=comparar(aleatorio);
					        velocideee(&velocidA);
				            gotoxy(6,6);
				            printf("HEALTH: %i",healthpoint);
                            gotoxy(6,7);
	                        printf("SCORE: %i",score);
					        }
					    else
					        valorflecha=valorbarrera;    
					        if(c==13)
					        c=b-1;
					}
		
		
		
		 if(aleatorio==1||aleatorio==7)
		 			{
					     //izauierda
                        Sleep(velocidA);
                        gotoxy(j,15);
                        textcolor(CYAN);
                        printf(">");
                        j++;
                        gotoxy(k,15);
                        putchar('\0');
                        k++;
                        gotoxy(6,6);
                        printf("HEALTH: %i",healthpoint);
                        gotoxy(6,7);
                        printf("SCORE: %i",score);
                        if(j==37)
                           	{
                            j=25;
                            valorflecha=3;
                            valorbarrera2=valorbarrera; 
                            aleatorio=comparar(aleatorio);
                            velocideee(&velocidA);
                            }
                        else
         	               valorflecha=valorbarrera;                               
                        	if(k==37)
                            k=j-1;
                    }
         if(aleatorio==4||aleatorio==8)
		 			{   
                        //derecha
                        Sleep(velocidA);
                        gotoxy(l,15);
                        textcolor(CYAN);
                        printf("<");
                        l--;
                        gotoxy(m,15);
                        putchar('\0');
                        m--;
                        gotoxy(6,6);
                        printf("HEALTH: %i",healthpoint);
                        gotoxy(6,7);
                        printf("SCORE: %i",score);
                        if(l==43)
                           	{       
                            l=50;
                            valorflecha=1;
                            valorbarrera2=valorbarrera; 
                            aleatorio=comparar(aleatorio);
                            velocideee(&velocidA);
                            }
                        else
         	               valorflecha=valorbarrera;                               
                            if(m==43)
                            m=l+1;
					}
                        
         if(aleatorio==2||aleatorio==6||aleatorio==9)
                    {
                        //abajo
                        Sleep(velocidA);
                        gotoxy(40,o);
                        textcolor(CYAN);
                        printf("^");
                        o--;
                        gotoxy(40,p);
                        putchar('\0');
                        p--;
                        gotoxy(6,6);
                        printf("HEALTH: %i",healthpoint);
                        gotoxy(6,7);
                        printf("SCORE: %i",score);
                        if(o==17)
                           	{  
                            o=24;
                            valorflecha=2;
                            valorbarrera2=valorbarrera; 
                           	aleatorio=comparar(aleatorio);
                           	velocideee(&velocidA);
                            }
                             else
         	                valorflecha=valorbarrera;
                                if(p==17)
                                    p=o+1;	
					}      
     }
if (kbhit())//usuario
   {
    char z;
    z=getch();
            switch(z)
               	{
	            	case 'w':
	             	{
                        limpiar();
                        gotoxy(40,13);
		                cprintf("%c",254);
		                valorbarrera=4; 
                        }
		                break;
		            case 'a':
	                 	{
                        limpiar();
			            gotoxy(37,15);
			            cprintf("%c",254);
		                valorbarrera=3; 
						}
		             	break;
                    case 's':
		                {
		           	    limpiar();
                        gotoxy(40,17);
	               	    cprintf("%c",254);
	                    valorbarrera=2;
                        }
	           	      	break;
	                case 'd':
		                {
		                limpiar();
                        gotoxy(43,15);
			            cprintf("%c",254);
	                    valorbarrera=1;
		                }
		               break;             
	            }
    }
}while (healthpoint>0);
return;
}


int main ()
{
	
    while(!kbhit())
	pintar_mapa();
	getch();
	clrscr();
	gotoxy(36,13);
	printf("WELCOME");
	Sleep(500);
    clrscr();
    menu();    
    srand(time(NULL));
	limpiar();
	gotoxy(40,15);
	textcolor(RED);
	cprintf("%c",3);
	flujo_de_flechas();
	clrscr();
	gotoxy(40,12);
	printf("END\a");
    Sleep(1000);
    clrscr();
    textcolor(CYAN);
    gotoxy(35,13);
    printf("Your score is: %i!!!!!",score);
    intro();
	getch();   
                 
return 0;
}
