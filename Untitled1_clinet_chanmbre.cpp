#include<iostream>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::microseconds;

//#include <wchar.h>
/******************************************************************************
/****************************Fonction gotoxy **********************************
/******************************************************************************/
void Color(int couleurDuTexte,int couleurDeFond);
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void gotoxy(short x,short y)
{
  COORD pos={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}  

/******************************************************************************
/***********************Les structures *****************************
/******************************************************************************/
typedef struct client
	                   {
                           char cin[12],nom[15],prn[15],adr[20],tel[12];
	                       int age,Num;
	                   }CLIENT;
CLIENT cl ;
typedef struct chambr
	                   {
                           char     nch [20] ,	avcblc [20],avpis [15] , respar[20] , av[25] , avo[25] , pav[25]="non" ;
	                       int 	    	 etgch ,nmbrlit ;
						   long     prix=2000 ,prip ,prixap   ;
	                   }CHAMBR ; 
CHAMBR ch ; 
typedef struct location
	                   {
                           char     nchl [20] ,ncll [20] ,	 noml[20] , prnl[20] ;
						   int 	 nbrj ,mont ,prixl ;
	                   }LOCATION ; 
LOCATION l ; 

/******************************************************************************
/***********************Les pointeurs de fichiers *****************************
/******************************************************************************/
FILE *fp,*fn,*fnv,*fch, *fnch , *fl;

void slow_print(const string & message_efecant, unsigned int micro_per_char)
{
	int i=0 ;
	gotoxy(70,3); 
        for (const char c: message_efecant)
    {
        cout << c << flush;
		if(c=='\n')
		{
			
		gotoxy(32,15+i);
		i++ ;
		}
		
        
        sleep_for(microseconds(10*micro_per_char));
    }
}

void slow_print_menu(const string& message_menu, unsigned int micro_per_char)
{
		int i=0;
		gotoxy(17,0);
        for (const char c: message_menu)
    {
        
        cout << c << flush;
        if(c=='\n')
		{
			
		gotoxy(17,1+i);
		i++ ;
		}
        
        sleep_for(microseconds(10*micro_per_char));
    }
}

void slow_print_enrgis_chamr(const string & message_info_chambr, unsigned int micro_per_char)
{
	int i=0 ;
	gotoxy(17,17); 
        for (const char c: message_info_chambr)
    {
        cout << c << flush;
		if(c=='\n')
		{
			
		gotoxy(17,18+i);
		i++ ;
		}
		
        
        sleep_for(microseconds(10*micro_per_char));
    }
}
void slow_print_client_location(const string & message_info_client_location, unsigned int micro_per_char)
{
	int i=0 ;
	gotoxy(20,21); 
        for (const char c: message_info_client_location)
    {
        cout << c << flush;
		if(c=='\n')
		{
			
		gotoxy(20,22+i);
		i++ ;
		}
		
        
        sleep_for(microseconds(10*micro_per_char));
    }
}
void slow_print_chambre_location(const string & message_info_chambre_location, unsigned int micro_per_char)
{
	int i=0 ;
	gotoxy(72,20); 
        for (const char c: message_info_chambre_location)
    {
        cout << c << flush;
		if(c=='\n')
		{
			
		gotoxy(72,21+i);
		i++ ;
		}
		
        
        sleep_for(microseconds(10*micro_per_char));
    }
}

void slow_print_enrgis_client_location(const string& message_info_location, unsigned int micro_per_char)
{
		int i=0;
		gotoxy(17,17);
        for (const char c: message_info_location)
    {
        
        cout << c << flush;
        if(c=='\n')
		{
			
		gotoxy(17,18+i);
		i++ ;
		}
        
        sleep_for(microseconds(10*micro_per_char));
    }
}

void slow_print_logo(const string& message_logo, unsigned int micro_per_char)
{
		int i=0;       
		gotoxy(17,0);  
        for (const char c: message_logo)
    {
        
        cout << c << flush;
        if(c=='\n')
		{
			
		gotoxy(17,1+i);
		i++ ;
		}

        
        sleep_for(microseconds(10*micro_per_char));
    }
}

void slow_print_interfass_person(const string& message_persson, unsigned int micro_per_char)
{
		int i=0;
		gotoxy(32,17);
        for (const char c: message_persson)
    {
        
        cout << c << flush;
        if(c=='\n')
		{
			
		gotoxy(32,18+i);
		i++ ;
		}

        
        sleep_for(microseconds(100*micro_per_char));
    }
}
void slow_print_client_a_reserver(const string& message_persson_a_reserver, unsigned int micro_per_char)
{
		int i=0;
		gotoxy(70,17);
        for (const char c: message_persson_a_reserver)
    {
        
        cout << c << flush;
        if(c=='\n')
		{
			
		gotoxy(70,18+i);
		i++ ;
		}

        
        sleep_for(microseconds(100*micro_per_char));
    }
}
void slow_print_enregisrement_person(const string & message_enregisrement_person, unsigned int micro_per_char)
{
	
	int i=0 ;
	gotoxy(60,25);  
        for (const char c: message_enregisrement_person)
    {
        cout << c << flush;
		
        
        sleep_for(microseconds(100*micro_per_char));
    }
}

void interface_enrgis_chambr()
{
	system("cls");
	string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
		string message_info_chambr =
					"\n         +----[Information sur la chambre]----+ " 
					"\n                                                " 	
					"\n  - Numero de la chambr       :" 		          
					"\n  - Etage de la chambr        :"		
					"\n  - Avec un balcon oui/non    :"
					"\n  - Avec une piscine oui/nom  :"			
					"\n  - Combien de lits 1/2       :"
					"\n                               "
					;
					
		slow_print_enrgis_chamr(message_info_chambr, 100);	
}

void interface_modifie_chambr()
{
	string message_info_chambr =
					"\n         +----[Information sur la chambre]----+ " 
					"\n                                                " 	
					"\n  - Numero de la chambr       :" 		          
					"\n  - Etage de la chambr        :"		
					"\n  - Avec un balcon oui/non    :"
					"\n  - Avec une piscine oui/nom  :"			
					"\n  - Combien de lits 1/2       :"
					
					;
					
		slow_print_enrgis_chamr(message_info_chambr, 100);
}
void enregistrer_chambre()

{
	system("slc");
	void interface_client() ;
	void rechercher_client_a_reserver();
	int ch1, ch2 ,tr;

	do
    {
	   interface_enrgis_chambr();
	   gotoxy(50,20);scanf("%s",ch.nch);  //gets(p.cin);
	   gotoxy(50,21);scanf("%d",&ch.etgch);
	   gotoxy(50,22);scanf("%s",ch.avcblc);
	   gotoxy(50,23);scanf("%s",ch.avpis);
	   gotoxy(50,24);scanf("%d",&ch.nmbrlit);
	    if (strcmp(ch.avcblc,"oui")==0)
	   {
	   	ch.prix=ch.prix+1000;
	   	
	   }
	   if (strcmp(ch.avpis,"oui")==0)
	   {
	   	ch.prix=ch.prix+1000;
	   	
	   }
	   
	   gotoxy(19,25);printf("- prix                       :");
	   
	   gotoxy(50,25);printf("%d",ch.prix); 
	  
	   
	  
	   gotoxy(17,27); 
	   printf("________________________________________________________________________________________________________");	
	   gotoxy(17,29); 
	   printf("voulez vous enregistrer o/n?:");			
	   ch1=getch();
	   if (toupper(ch1)=='O')
       {
		 fch=fopen("d:\\cpp_fils\\chambr.don","a");
		 fwrite(&ch,sizeof(ch),1,fch);
		 fclose(fch);
	  }
	  gotoxy(17,31);
      printf("voulez vous ajouter une autre chambr  o/n?:");
	  ch2=getch();
	} while(toupper(ch2)=='O');

}
void rechercher_client_a_reserver(){
	void enregistrer_client_a_reserver() ;
	  char cinp[12];
	  char ch3 [20] ;
      int tr=0;
      	void  interface_client_a_reserver();
	  
	  fp=fopen("d:\\cpp_fils\\client.don","r");
	  if(fp==NULL)
      { 
         gotoxy(55,26);printf("Fichier introuvable!!!");
      }
	  else
      {
	      do
          {
	         fread(&cl,sizeof(cl),1,fp);
             if (strcmp(ch.respar,cl.nom)==0)
             {
	            interface_client_a_reserver();
	            gotoxy(98,20);printf("%s",cl.cin);
	            gotoxy(98,21);printf("%s",cl.nom);
	            gotoxy(98,22);printf("%s",cl.prn);
	            gotoxy(98,23);printf("%s",cl.adr);
                gotoxy(98,24);printf("%s",cl.tel);   
	            gotoxy(98,25);printf("%d",&cl.age);
	            tr=1;
	            
             }
       }while (!feof(fp)&&(strcmp(ch.respar,cl.nom)!=0));
       fclose(fp);
	   if (tr==0)
       {
		  
		  gotoxy(17,27); 
	  	  printf("________________________________________________________________________________________________________");
		  gotoxy(17,28);
		  printf("%s",ch.respar);printf("  Pas de personne avec ce nom!!!"); 
		  
		  
		  
	   }
    }
}
void modifier_chambr()
{

   int pos,ln,q,tr=0;
   char ncp [20];
   do{
      system("cls");
	string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
     gotoxy(17,20);printf(" -------Modifier une chambre-------");
     gotoxy(17,22);printf("Numéro de la chambre à modifier :     ");
     gotoxy(17,24);scanf("%s",ncp);
     fch=fopen("d:\\cpp_fils\\chambr.don","r");
     if(fch==NULL)
     { 
                 gotoxy(10,24);
                 printf("Fichier introuvable!!!");
     }
     else
     {
       do{
          pos=ftell(fch);
          fread(&ch,sizeof(ch),1,fch);
	      if (strcmp(ncp,ch.nch)==0)
          {
          	gotoxy(17,20);printf("                                     ");
			gotoxy(18,20);printf("                                     ");
			gotoxy(19,20);printf("                                     "); 
          	
	            interface_modifie_chambr();
	   gotoxy(50,20);printf("%s",ch.nch);  
	   gotoxy(50,21);printf("%d",&ch.etgch);
	   gotoxy(50,22);printf("%s",ch.avcblc);
	   gotoxy(50,23);printf("%s",ch.avpis);
	   gotoxy(50,24);printf("%d",&ch.nmbrlit);
	   gotoxy(50,25);printf("%s",ch.respar);
	            tr=1;
             }
	}while (!feof(fch)&&(strcmp(ncp,ch.nch)!=0));
	if (tr==0){
gotoxy(17,26);printf("Pas de personne avec ce Numéro!!!");
	}
	else{
	    fclose(fch);
	    do{
gotoxy(17,30); printf("Numéro de la ligne à modifier:");
              gotoxy(48,30);scanf("%d",&ln);
	          switch(ln)
{ 
  					 case 1 :gotoxy(50,20);printf("                         ");gotoxy(50,20);scanf("%s",ch.nch);gotoxy(26,13);break;
 					 case 2 :gotoxy(50,21);printf("                         ");gotoxy(50,21);scanf("%d",ch.etgch);gotoxy(26,17);break;
		             case 3 :gotoxy(50,22);printf("                         ");gotoxy(50,22);scanf("%s",ch.avcblc);gotoxy(50,21);break;
		             case 4 :gotoxy(50,23);printf("                         ");gotoxy(50,23);scanf("%s",ch.avpis);gotoxy(26,25);break;
		             case 5 :gotoxy(50,24);printf("                         ");gotoxy(50,24);scanf("%d",ch.nmbrlit);gotoxy(26,29);break;
		             case 6 :gotoxy(59,25);printf("<<< - vous ne pouvez pas changer cette information");
               }
               gotoxy(17,30); printf("                                                                                              ");
			   gotoxy(17,30); printf("_______________________________________________________________________________________________________________");
               gotoxy(17,31); printf("Autre ligne à modifier o/n:");
               
               gotoxy(48,31);q=getch();
	     }while(toupper(q)=='O');
	     gotoxy(17,33); printf("Voulez vous vraiment modifier cet enregistrement o/n?");
         q=getch();
         if(toupper(q)=='O')
         {
            fch=fopen("d:\\cpp_fils\\chambr.don","r+");
            fseek(fch,pos,0);
            fwrite(&ch,sizeof(ch),1,fch);
            fclose(fch);
         }
         }
         }
         gotoxy(17,35); printf("modifier un autre enregistrement o/n?:");
         q=getch();
     }while(toupper(q)=='O');
     }
void rechercher_chambr(){
	  char cinp[12];
      int tr=0;
      system("cls");
	  string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);	
		
	  gotoxy(17,19);
     	  printf("Numéro de la client à rechercher :");
	  gotoxy(51,19);
	  scanf("%s",cinp);
	  fn=fopen("d:\\cpp_fils\\chambr.don","r");
	  if(fch==NULL)
      { 
         gotoxy(17,21);printf("Fichier introuvable!!!");
      }
	  else
      {
	      do
          {
	         fread(&ch,sizeof(ch),1,fch);
             if (strcmp(cinp,ch.nch)==0)
             {
	           gotoxy(50,20);printf("%s",ch.nch);  
	   gotoxy(50,21);printf("%d",&ch.etgch);
	   gotoxy(50,22);printf("%s",ch.avcblc);
	   gotoxy(50,23);printf("%s",ch.avpis);
	   gotoxy(50,24);printf("%d",&ch.nmbrlit);
	   
	            tr=1;
             }
       }while (!feof(fch)&&(strcmp(cinp,ch.nch)!=0));
	   if (tr==0)
       {
		  gotoxy(17,21);printf("%s",cinp);printf("Pas de personne avec ce Numéro!!!");
	   }
    }
    gotoxy(40,27);printf("Taper une touche pour revenir au menu principal  ");
    getch();
}
void lister_chambre()
{ 
      system("cls");
				
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
					
     				 int i=0;
     			    gotoxy(32,18);
                    printf("+---------------------------------------+");
     				gotoxy(32,19);
                    printf("+         La liste des chambre          +");
                    gotoxy(32,20);
                    printf("+---------------------------------------+");
     			    gotoxy(17,21);
                    printf("========================================================================================================");
	                gotoxy(17,22);
                    printf("|Num de la chambr |");              
      				gotoxy(17,23);        
      				printf("|-----------------|");
	  				gotoxy(36,22);
      				printf("Etage du chambr   |");
     				gotoxy(36,23);
     				printf("------------------|");
	                gotoxy(55,22);
                    printf("avec un balcon |");  
      				gotoxy(55,23);
      				printf("---------------|");
	  				gotoxy(71,22);
      				printf("avec une piscine |");
      				gotoxy(71,23);
      				printf("-----------------|");
	  				gotoxy(89,22);
      				printf("nombre de lits |");  
      				gotoxy(89,23);
      				printf("---------------|");
      				gotoxy(106,22);
      				printf("disponible     |");  
      				gotoxy(105,23);
      				printf("---------------|");
	  
	  fch=fopen("d:\\cpp_fils\\chambr.don","r");
	  do
      {
	     fread(&ch,sizeof(ch),1,fch);
	     if(!feof(fch))
         {
	                   i++;
	                   gotoxy(19,22+i*2);	Color(10,0); printf("%s",ch.nch); 	Color(15,0);
	                   gotoxy(17,23+i*2);
     					 printf("|-----------------|") ;
					   gotoxy(17,22+i*2);printf("|");
					   gotoxy(35,22+i*2);printf("|");
	                   gotoxy(40,22+i*2);printf("%d",ch.etgch);
	                   gotoxy(36,23+i*2);
   					     printf("------------------|");
					   gotoxy(54,22+i*2);printf("|");
	                   gotoxy(57,22+i*2);	Color(9,0);printf("%s",ch.avcblc); 	Color(15,0);
	                   gotoxy(55,23+i*2);
    				     printf("---------------|");
					   gotoxy(70,22+i*2);printf("|");
	                   gotoxy(73,22+i*2);	Color(9,0);printf("%s",ch.avpis); 	Color(15,0);
	                   gotoxy(71,23+i*2);
      					 printf("-----------------|");
					   gotoxy(88,22+i*2);printf("|");
	                   gotoxy(92,22+i*2);printf("%d",ch.nmbrlit);
	                   gotoxy(89,23+i*2);
               			 printf("---------------|");
               			  gotoxy(104,22+i*2);printf("|");
               			  gotoxy(108,22+i*2);	Color(10,0);printf("%s",ch.av
							 o);  	Color(15,0);
	                   gotoxy(104,23+i*2);
               			 printf("|---------------|");
               			  gotoxy(120,22+i*2);printf("|");
					  
	                   
	                   
	                   
		}
      } while(!feof(fch));
	  fclose(fch);
	  gotoxy(18,30+i*2);
      printf("Taper une touche pour revenir au menu principal : ");
	  
	  getch();
}

void interface_client_location()
{
	string message_info_client_location =
					
					
				
						
					"\n- nom du client           :"
					"\n- prenom du client        :"
					"\n- adress                  :"
					"\n- telephone               :"
					"\n- age                     :"
					
					 		          
					
					;
					
		slow_print_client_location(message_info_client_location, 100);
}
void interface_chambre_location()
{
	string message_info_chambre_location =
					
					
				
						
					"\n - etage de la chambre     :"
					"\n - avec balcan             :"
					"\n - avec douche             :"
					"\n - nombre de lit           :"
					"\n - prix                    :"
					"\n - montan                  :"
					
					 		          
					
					;
					
		slow_print_chambre_location(message_info_chambre_location, 100);
}
void enregistrer_location()

{
	
	system("cls");
	string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);

	int ch1, ch2 ,tr,ps;
    
	do
    {
	   
	   	
		    gotoxy(17,18); Color(9,0);printf("         +-----information sur le client-----+") ; Color(15,0);
		    gotoxy(17,19);printf("____________________________________________________") ;
		      gotoxy(17,29); 
	   printf("________________________________________________________________________________________________________");
		    gotoxy(17,17);printf("||") ;
             	gotoxy(17,17);printf("||") ;
             	gotoxy(17,18);printf("||") ;
             	gotoxy(17,19);printf("||") ;
             	gotoxy(17,20);printf("||") ;
				 gotoxy(17,21);printf("||") ;
             	gotoxy(17,22);printf("||") ;
             	gotoxy(17,23);printf("||") ;
             	gotoxy(17,24);printf("||") ;
             	gotoxy(17,25);printf("||") ;
             	gotoxy(17,26);printf("||") ;
             	gotoxy(17,27);printf("||") ;
             	gotoxy(17,28);printf("||") ;
             	gotoxy(17,29);printf("||") ;
		 gotoxy(20,21); 
		printf("- cin du client           :") ;
		   
		   
	   do
	   	{	
	   	fn=fopen("d:\\cpp_fils\\client.don","r");
		
	   		gotoxy(49,21); Color(11,0);
			scanf("%s",l.ncll); Color(15,0);
	   		tr=0;
	   		do
	   		{
	   			fread(&cl,sizeof(cl),1,fn);
             	if (strcmp(l.ncll,cl.cin)==0)
             	{
             	
	            	interface_client_location();
	             	Color(10,0);gotoxy(49,22);printf("%s",cl.nom);strcpy(l.noml,cl.nom);

	            	gotoxy(49,23);printf("%s",cl.prn);strcpy(l.prnl,cl.prn);
	            	gotoxy(49,24);printf("%s",cl.adr);
                	gotoxy(49,25);printf("%s",cl.tel);   
	            	gotoxy(49,26);printf("%d",cl.age); Color(15,0);
	            	tr=1;
	          
             	}	
        	}while(!feof(fn)&&(strcmp(l.ncll,cl.cin)!=0));
        	fclose(fn);
             if (tr==0)
             {
             	gotoxy(49,21);Color(12,0);printf("NUMERO DU CLIENT INVALID") ;Color(15,0);
             	sleep(2);
             	gotoxy(49,21);printf("                             ") ; 
             	gotoxy(49,21);Color(10,0);printf("RESSAYER") ;Color(15,0);
             	
             	sleep(2);
             	gotoxy(49,21);printf("        ") ;
             	gotoxy(49,21);printf("") ;
			 }
             
	    
	    
	   }while(tr==0);
	   
		
		gotoxy(20,27); printf("- nombre de jour          :") ;Color(10,0);gotoxy(49,27);scanf("%d",&l.nbrj);Color(15,0);
		
		gotoxy(20,28); printf("- numero de la chambre    :") ;
		do{
			fch=fopen("d:\\cpp_fils\\chambr.don","r");
		gotoxy(49,28);
			
			Color(10,0);scanf("%s",l.nchl);Color(15,0);
			tr=0;
			do
	  	 {
	  	 	ps=ftell(fch) ;
			fread(&ch,sizeof(ch),1,fch);
             if (strcmp(l.nchl,ch.nch)==0)
             { 
             	
				gotoxy(69,17);printf("|") ;
             	gotoxy(69,17);printf("|") ;
             	gotoxy(69,18);printf("|") ;
             	gotoxy(69,19);printf("|") ;
             	gotoxy(69,20);printf("|") ;
				gotoxy(69,21);printf("|");
             	gotoxy(69,22);printf("|") ;
             	gotoxy(69,23);printf("|") ;
             	gotoxy(69,24);printf("|") ;
             	gotoxy(69,25);printf("|") ;
             	gotoxy(69,26);printf("|") ;
             	gotoxy(69,27);printf("|") ;
             	gotoxy(69,28);printf("|") ;
             	gotoxy(69,29);printf("|") ;
             	gotoxy(119,17);printf("||") ;
             	gotoxy(119,17);printf("||") ;
             	gotoxy(119,18);printf("||") ;
             	gotoxy(119,19);printf("||") ;
             	gotoxy(119,20);printf("||") ;
				gotoxy(119,21);printf("||") ;
             	gotoxy(119,22);printf("||") ;
             	gotoxy(119,23);printf("||") ;
             	gotoxy(119,24);printf("||") ;
             	gotoxy(119,25);printf("||") ;
             	gotoxy(119,26);printf("||") ;
             	gotoxy(119,27);printf("||") ;
             	gotoxy(119,28);printf("||") ;
             	gotoxy(119,29);printf("||") ;
                gotoxy(78,18);Color(9,0);printf("+----information sur la chambre----+") ;Color(15,0);
                gotoxy(70,19);printf("_________________________________________________") ;
	            interface_chambre_location() ;
	            Color(10,0);gotoxy(103,21);printf("%d",ch.etgch);
	            gotoxy(103,22);printf("%s",ch.avcblc);
	   			gotoxy(103,23);printf("%s",ch.avpis);
	   			gotoxy(103,24);printf("%d",ch.nmbrlit);
	   			gotoxy(103,25);printf("%d",ch.prix);
				gotoxy(103,25);printf("%d",ch.prix);  strcpy(ch.avo,"non");
	   			l.mont=l.nbrj*ch.prix ;
	   			gotoxy(103,26);printf("%d",l.mont);Color(15,0);
	   			
	   			
	            tr=1;
             }
             }while(!feof(fch)&&(strcmp(l.nchl,ch.nch)!=0));
             fclose(fch); 
             if (tr==0)
             {
             	gotoxy(49,28);Color(12,0);printf("NUMERO DU CHAMBRE INVALID") ;Color(15,0);
             	sleep(2);
             	gotoxy(49,28);printf("                             ") ; 
             	gotoxy(49,28);Color(10,0);printf("RESSAYER") ;Color(15,0);
             	
             	sleep(2);
             	gotoxy(49,28);printf("        ") ;
             	gotoxy(49,28);printf("") ;
			 }
             
             
	   		
	   }while(tr==0);
		
	   	
	   gotoxy(17,32); 
	   printf("voulez vous enregistrer o/n?:");			
	   ch1=getch();
	   if (toupper(ch1)=='O')
       {
		 fl=fopen("d:\\cpp_fils\\location.don","a");
		 fwrite(&l,sizeof(l),1,fl);
		 fclose(fl);
		 fch=fopen("d:\\cpp_fils\\chambr.don","r+");
		 fseek(fch,ps,0);
		 fwrite(&ch,sizeof(ch),1,fch);
		 fclose(fch);
	  }
	  gotoxy(17,34);
      printf("voulez vous ajouter une autre location  o/n?:");
	  ch2=getch();
	} while(toupper(ch2)=='O');

}
void lister_location()
{ 
      system("cls");
				
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
					
     				 int i=0;
     			    gotoxy(32,18);
                    printf("+---------------------------------------+");
     				gotoxy(32,19);
                    printf("+         La liste des location          +");
                    gotoxy(32,20);
                    printf("+---------------------------------------+");
     			    gotoxy(17,21);
                    printf("========================================================================================================");
	                gotoxy(17,22);
                    printf("|  Num du client  |");              
      				gotoxy(17,23);        
      				printf("|-----------------|");
	  				gotoxy(36,22);
      				printf("Nom du client     |");
     				gotoxy(36,23);
     				printf("------------------|");
	                gotoxy(55,22);
                    printf("prenom client  |");  
      				gotoxy(55,23);
      				printf("---------------|");
	  				gotoxy(71,22);
      				printf("N_joure|");
      				gotoxy(71,23);
      				printf("---------|");
      				gotoxy(79,22);
      				printf("N_chambre|");
      				gotoxy(79,23);
      				printf("---------|");
	  				gotoxy(89,22);
      				printf("prix           |");  
      				gotoxy(89,23);
      				printf("---------------|");
      				gotoxy(106,22);
      				printf("monton a payer|");  
      				gotoxy(105,23);
      				printf("---------------|");  
	  
	  fl=fopen("d:\\cpp_fils\\location.don","r");
	  do
      {
	     fread(&l,sizeof(l),1,fl);
	     if(!feof(fl))
         {
	                   i++;
	                   gotoxy(19,22+i*2);	Color(10,0); printf("%s",l.ncll);  	Color(15,0);
	                   gotoxy(17,23+i*2);
     					 printf("|-----------------|") ;
					   gotoxy(17,22+i*2);printf("|");
					   gotoxy(35,22+i*2);printf("|");
	                  gotoxy(40,22+i*2);	Color(9,0);printf("%s",l.noml); 	Color(15,0);
	                   gotoxy(36,23+i*2);
   					     printf("------------------|");
					   gotoxy(54,22+i*2);printf("|");
	                   gotoxy(57,22+i*2);	Color(9,0);printf("%s",l.prnl);    	Color(15,0);
	                   gotoxy(55,23+i*2);
    				     printf("---------------|");
					   gotoxy(70,22+i*2);printf("|");
	                   gotoxy(73,22+i*2);printf("%d",l.nbrj);
	                   gotoxy(71,23+i*2);
      					 printf("-----------------|");
					   gotoxy(88,22+i*2);printf("|");
					    gotoxy(79,22+i*2);printf("|"); gotoxy(80,22+i*2);printf("%s",l.nchl);
					    gotoxy(79,23+i*2);printf("|");
					   l.prixl=l.mont/l.nbrj;
	                   gotoxy(92,22+i*2);printf("%d",l.prixl);
	                   gotoxy(89,23+i*2);
               			 printf("---------------|");
               			  gotoxy(104,22+i*2);printf("|");
               			  gotoxy(108,22+i*2);	Color(12,0);printf("%d",l.mont); 	Color(15,0);
	                   gotoxy(104,23+i*2);
               			 printf("|---------------|");
               			  gotoxy(120,22+i*2);printf("|");
					  
	                   
	                   
	                   
		}
      } while(!feof(fl));
	  fclose(fl);
	  gotoxy(18,30+i*2);
      printf("Taper une touche pour revenir au menu principal : ");
	  
	  getch();
}
void interface_client()
{
		system("cls");
				
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
		string message_persson =
					"\n                   ------Information sur la personne------                 "
						"\nCIN personne		:" 		
						"\nNom personne		:"		
						"\nPrénom personne		:"
						"\nAdresse			:"			
						"\nTélephone		:"
						"\nAge			:"
						;
		slow_print_interfass_person(message_persson, 100);
	
}
void enregistrer_client_a_reserver(){
	void interface_client_a_reserver();
	int ch1,ch2;
	do
    {
	     interface_client_a_reserver();
		gotoxy(98,20);printf("%s",cl.cin);
        gotoxy(98,21);printf("%s",cl.nom);
        gotoxy(98,22);printf("%s",cl.prn);
	    gotoxy(98,23);printf("%s",cl.adr);
        gotoxy(98,24);printf("%s",cl.tel);   
	    gotoxy(98,25);printf("%d",&cl.age);
	            
	   gotoxy(98,26);
	   printf("voulez vous enregistrer o/n?:");	
		
	   ch1=getch();
	   if (toupper(ch1)=='O')
       {
		 fp=fopen("d:\\cpp_fils\\client.don","a");
		 fwrite(&cl,sizeof(cl),1,fp);
		 fclose(fp);
	  }
	  ch2=getch();
	  }while(toupper(ch2)=='O');
 } 
void interface_client_a_reserver()
{
		
		string message_persson_a_reserver =
					"\n      +-----Information sur la personne-----+"
					"\n                                             "
					"\n|  CIN personne      :" 		
					"\n|  Nom personne      :"		
					"\n|  Prénom personne   :"
					"\n|  Adresse           :"			
					"\n|  Télephone         :"
					"\n|  Age               :";
		slow_print_client_a_reserver(message_persson_a_reserver, 100);
	
}

void enregistrer_client(){
	int ch1,ch2;
	do
    {
	   interface_client();
	   gotoxy(58,19);scanf("%s",cl.cin);  //gets(p.cin);
	   gotoxy(58,20);scanf("%s",cl.nom);
	   gotoxy(58,21);scanf("%s",cl.prn);
	   gotoxy(58,22);scanf("%s",cl.adr);
	   gotoxy(58,23);scanf("%s",cl.tel);
	   gotoxy(58,24);scanf("%d",&cl.age);
	  printf( "________________________________________________________________________________________________________") ;
	   gotoxy(17,26);
	   printf("voulez vous enregistrer o/n?:");	
		
	   ch1=getch();
	   if (toupper(ch1)=='O')
       {
		 fp=fopen("d:\\cpp_fils\\client.don","a");
		 fwrite(&cl,sizeof(cl),1,fp);
		 fclose(fp);
	  }
	  gotoxy(17,28);
      printf("voulez vous ajouter une autre compte  o/n?:");
	  ch2=getch();
	  }while(toupper(ch2)=='O');
 } 

void lister_client()
{ 
      system("cls");
				
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
					
      int i=0;
      gotoxy(32,18);
      printf("+---------------------------------------+");
	  gotoxy(32,19);
      printf("+         La liste des personnes        +");
      gotoxy(32,20);
      printf("+---------------------------------------+");
      gotoxy(17,21);
      printf("===============================================================");  
	  gotoxy(17,22);
      printf("|Carte d'idendite|");  
      gotoxy(17,23);
      printf("|----------------|");
	  gotoxy(35,22);
      printf(" Les noms |");
      gotoxy(35,23);
      printf("----------|");
	  gotoxy(46,22);
      printf("Prenoms|");
      gotoxy(46,23);
      printf("-------|");
	  gotoxy(54,22);
      printf("Adresses |");
      gotoxy(54,23);
      printf("---------|");
	  gotoxy(64,22);
      printf("Telephone |");  
      gotoxy(64,23);
      printf("----------|");
	  gotoxy(75,22);
      printf("Ages|");
      gotoxy(75,23);
      printf("----|");
      
      
      
      
      
	  fn=fopen("d:\\cpp_fils\\client.don","r");
	  fch=fopen("d:\\cpp_fils\\chambr.don","r");
	  
	  do
      {
	     fread(&cl,sizeof(cl),1,fn);
	     if(!feof(fn))
         {
	                   i++;
	                   gotoxy(18,22+i*2);	Color(10,0); printf("%s",cl.cin); 	Color(15,0);
	                   gotoxy(17,23+i*2);
     					 printf("|----------------|");
					   gotoxy(17,22+i*2);printf("|");
					   gotoxy(34,22+i*2);printf("|");
	                   gotoxy(35,22+i*2);	Color(10,0);printf("%s",cl.nom);	Color(15,0);
	                   gotoxy(35,23+i*2);
   					     printf("----------|");
					   gotoxy(45,22+i*2);printf("|");
	                   gotoxy(46,22+i*2);	Color(10,0);printf("%s",cl.prn); 	Color(15,0);
	                   gotoxy(46,23+i*2);
    				     printf("-------|");
					   gotoxy(53,22+i*2);printf("|");
	                   gotoxy(55,22+i*2);printf("%s",cl.adr);
	                   gotoxy(54,23+i*2);
      					 printf("---------|");
					   gotoxy(63,22+i*2);printf("|");
	                   gotoxy(65,22+i*2);printf("%s",cl.tel);
	                   gotoxy(64,23+i*2);
               			 printf("----------|");
					   gotoxy(74,22+i*2);printf("|");
	                   gotoxy(76,22+i*2);printf("%d",cl.age);
	                   gotoxy(75,23+i*2);
  					     printf("----|");
  					   gotoxy(79,22+i*2);printf("|");
  					   
  					   
  					
	                   
		}
      } while(!feof(fn));
	  fclose(fn);
	  gotoxy(18,30+i*2);
      printf("Taper une touche pour revenir au menu principal : ");
	  
	  getch();
}

void rechercher_client(){
	  char cinp[12];
      int tr=0;
      system("cls");
				
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
	  gotoxy(42,19);
     	  printf("Numéro de la client à rechercher :");
	  gotoxy(79,19);
	  scanf("%s",cinp);
	  fn=fopen("d:\\cpp_fils\\client.don","r");
	  if(fn==NULL)
      { 
         gotoxy(70,21);printf("Fichier introuvable!!!");
      }
	  else
      {
	      do
          {
	         fread(&cl,sizeof(cl),1,fn);
             if (strcmp(cinp,cl.cin)==0)
             {
	            interface_client();
	            gotoxy(58,19);printf("%s",cl.cin);
	            gotoxy(58,20);printf("%s",cl.nom);
	            gotoxy(58,21);printf("%s",cl.prn);
	            gotoxy(58,22);printf("%s",cl.adr);
                gotoxy(58,23);printf("%s",cl.tel);   
	            gotoxy(58,24);printf("%d",cl.age);
	            tr=1;
             }
       }while (!feof(fn)&&(strcmp(cinp,cl.cin)!=0));
	   if (tr==0)
       {
		  gotoxy(40,21);printf("%s",cinp);printf("Pas de personne avec ce Numéro!!!");
	   }
    }
    gotoxy(40,27);printf("Taper une touche pour revenir au menu principal  ");
    getch();
}

void modifier_client()
{

   int pos,ln,q,tr=0;
   char ncp[12];
   do{
      system("cls");
	string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
     gotoxy(10,20);printf(" -------Modifier une personne-------");
     gotoxy(10,22);printf("Numéro de la personne à modifier :     ");
     gotoxy(49,22);scanf("%s",ncp);
     fn=fopen("d:\\cpp_fils\\client.don","r");
     if(fn==NULL)
     { 
                 gotoxy(10,24);
                 printf("Fichier introuvable!!!");
     }
     else
     {
       do{
          pos=ftell(fp);
          fread(&cl,sizeof(cl),1,fn);
	      if (strcmp(ncp,cl.cin)==0)
          {
	            interface_client();
	            gotoxy(58,19);printf("%s",cl.cin);
	            gotoxy(58,20);printf("%s",cl.nom);
	            gotoxy(58,21);printf("%s",cl.prn);
	            gotoxy(58,22);printf("%s",cl.adr);
                    gotoxy(58,23);printf("%s",cl.tel);   
	            gotoxy(58,24);printf("%d",cl.age);
	            tr=1;
             }
	}while (!feof(fn)&&(strcmp(ncp,cl.cin)!=0));
	if (tr==0){
	   gotoxy(10,26);printf("Pas de personne avec ce Numéro!!!");
	}
	else{
	    fclose(fn);
	    do{
              gotoxy(10,28); printf("Numéro de la ligne à modifier:");
              gotoxy(40,26);scanf("%d",&ln);
	          switch(ln)
              {
		             case 1 :gotoxy(58,19);printf("                                ");gotoxy(58,19);scanf("%s",cl.cin);gotoxy(26,13);break;
		             case 2 :gotoxy(58,20);;printf("                                ");gotoxy(58,20);scanf("%s",cl.nom);gotoxy(26,17);break;
		             case 3 :gotoxy(58,21);printf("                                ");gotoxy(58,21);scanf("%s",cl.prn);gotoxy(26,21);break;
		             case 4 :gotoxy(58,22);printf("                                ");gotoxy(58,22);scanf("%s",cl.adr);gotoxy(26,25);break;
		             case 5 :gotoxy(58,23);printf("                                ");gotoxy(58,23);scanf("%s",cl.tel);gotoxy(26,29);break;
		             case 6 :gotoxy(58,24);printf("                                ");gotoxy(58,24);scanf("%d",cl.age);gotoxy(26,9);break;
               }
               gotoxy(16,33); printf("                                                      ");
               gotoxy(16,33); printf("Autre ligne à modifier o/n:");
               gotoxy(48,33);q=getch();
	     }while(toupper(q)=='O');
	     gotoxy(14,33); printf("                                                          ");
         gotoxy(14,33); printf("Voulez vous vraiment modifier cet enregistrement o/n?");
         q=getch();
         if(toupper(q)=='O')
         {
            fp=fopen("d:\\cpp_fils\\client.don","r+");
            fseek(fp,pos,0);
            fwrite(&cl,sizeof(cl),1,fp);
            fclose(fp);
         }
         }
         }
         gotoxy(14,33); printf("                                                          ");
         gotoxy(14,33); printf("modifier un autre enregistrement o/n?:");
         q=getch();
     }while(toupper(q)=='O');
     }

void supprimer_client(){
   int tr,rep,ch1;
   char c[12];
   do{
	tr=0;
	system("cls");
	   		
		string message_logo = "\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|";
					slow_print_logo(message_logo, 30);
       gotoxy(10,20);
	   fn=fopen("d:\\cpp_fils\\client.don","r");
	   printf("Numéro de la carte d'idendité de la personne à supprimer :");
	    gotoxy(85,20);
	   scanf("%s",c);
       fnv=fopen("d:\\cpp_fils\\newclient.don","w");
       fclose(fnv);
       fnv=fopen("d:\\cpp_fils\\newclient.don","a");
        if(fnv!=NULL)
        {
          while(!feof(fn))
          {
             fread(&cl,sizeof(cl),1,fn);
             if (strcmp(c,cl.cin)!=0)
             //if(!feof(fp))
             {
               //if (strcmp(c,p.cin)!=0)
               if(!feof(fn))
                   fwrite(&cl,sizeof(cl),1,fnv);
             }
               else 
               {
                interface_client();
	            gotoxy(58,19);printf("%s",cl.cin);
	            gotoxy(58,20);printf("%s",cl.nom);
	            gotoxy(58,21);printf("%s",cl.prn);
	            gotoxy(58,22);printf("%s",cl.adr);
                gotoxy(58,23);printf("%s",cl.tel);   
	            gotoxy(58,24);printf("%d",cl.age);
	            tr=1;
             }
          }
	   fclose(fn);
	   fclose(fnv);
	   if(tr==1)
       {
          gotoxy(55,27);printf("Voulez vous  supprimer cette personne o/n?:");
          ch1=getch();
	      if (toupper(ch1)=='O'){
             remove("d:\\cpp_fils\\client.don");
	         rename("d:\\cpp_fils\\newclient.don","d:\\cpp_fils\\client.don");
	         gotoxy(55,27);printf("                                                ");
       	     gotoxy(55,27);printf("La personne est supprimée!");
             //getch();
          }
	      else remove("d:\\cpp_fils\\newclient.don");
       }
       else{
            remove("d:\\cpp_fils\\newclient.don");
	        gotoxy(55,27);printf("Numéro introuvable!");
	        getch();
       }
	   gotoxy(55,29);printf("Autre personne à supprimer o/n?:");
	   rep=getch();
    }
   
	}while(toupper(rep)=='O');
   }

void menugenerale()
{
	int opt ;
	do
	{
		system("cls");
		

	string message_menu ="\n________________________________________________________________________________________________________"
					"\n| ____________________________________________________________________________________________________ |"
					"\n||                          __          __        __    _       _    ____     ____                    ||"   
					"\n||                         /  \\         \\ \\      / /   | |     | |   |   \\   /   |                    ||"
					"\n||                        / /\\ \\         \\ \\    / /    | |_____| |   |    \\_/    |                    ||"
					"\n||                       / /__\\ \\   ____  \\ \\  / /     |  _____  |   |  |\\   /|  |                    ||"
                    "\n||                      / /----\\ \\ |____|  \\ \\/ /      | |     | |   |  | \\_/ |  |                    ||"
					"\n||                     / /      \\ \\         \\  /       | |     | |   |  |     |  |                    ||"
					"\n||                    /_/        \\_\\         \\/        |_|     |_|   |__|     |__|                    ||"
					"\n||                                                                                                    ||"
                    "\n||                                      +-----------------------+                                     ||"
                    "\n||------------------------------------  + WELCOM TO A-VHM HOTEL +   ----------------------------------||"	
                    "\n||                                      +-----------------------+                                     ||"
					"\n||                                                                                                    ||"	                     
	                "\n||____________________________________________________________________________________________________||"		
					"\n|______________________________________________________________________________________________________|"
					
					"\n                                                                                        "                                                          
					"\n+------[ MENU CLIENT ]------+""    ""+-------[ MENU  chambre ]------+""       ""+----[ MENU location ]-------+"
						"\n                                                                     "                                              
					"\n| 1. enregistre un client   |""    ""| 6. enregistrer une chambre   |""       ""| 1. enregistre une location |"						
					                                                                           
					"\n| 2. lister les client      |""    ""| 7. lister les chambre        |""       ""| 1. lister les location     |"											
					     
					"\n| 3. recherche un client    |""    ""| 8. modifier une chambr       |""       ""| 1. modifier une location   |"											
					      
					"\n| 4. suprimer un client     |""    ""| 1. recherche  une chambre    |""       ""| 1. suprimer une location   |"											
					     
					"\n| 5. modifier un client     |""    ""| 1. suprimer  une chambre     |""       ""| 1. recherche une location  |"											
					
					"\n\n    Enter Option: ";
				
     slow_print_menu(message_menu, 30);
     			
gotoxy(50,26);
				scanf("%d",&opt);fflush(stdin);
	 switch(opt)
			{
				case 1:enregistrer_client();break;
				case 2:lister_client();break;
				case 3:rechercher_client();break;
				case 4:supprimer_client();break;	
				case 5:modifier_client();break;	
				case 6:enregistrer_chambre();break;
				case 7:lister_chambre();break;
				case 8:modifier_chambr();break;
				case 9:enregistrer_location();break;
				case 10:lister_location();break;
	 		}
    }while (opt<11);
	}

main()
{
	system("cls");
    
	menugenerale();
}


