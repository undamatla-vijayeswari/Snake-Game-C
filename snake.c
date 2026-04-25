#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
    
    int l,b;
    printf("GAME RULES:\nEnter 'a' to move left\nEnter 's'  to move left\nEnter 'w'  to move up\nEnter 'z' to move down\n");
    
    printf("GAME OVER IF SNAKE HITS BOUNDARY\n");
    
    printf("Enter length:");
    scanf("%d",&l);
    
    printf("Enter width:");
    scanf("%d",&b);
    
    int x = b/2 ,y = l/2;
    
    int foodx,foody;
    
    int score = 0;
   
    char ch;
    
    foodx = rand()%(l-2) + 1;
   
    foody = rand()%(b-2) + 1;
    while(1)
    {
        system("clear");
        int i,j;
        for(int i = 0 ;i<l/2;i++){
            printf(" ");
        }
       
        printf("SCORE:%d \n",score);
        
       
        for(i = 0;i<l;i++){
            
            for(j = 0 ;j < b;j++){
                
                if( i == 0|| i == l-1 || j== 0|| j==b-1)
                    printf("#");
                 
                else if( i== y && j== x)
                    printf("0");
               
                else if( i== foody && j== foodx )
                    printf("F");
               
                else
                    printf(" ");
             
            }
            printf("\n");
        }
        
        printf("Enter direction: \n");
        scanf("%c",&ch);
        
        if(ch == 'w'|| ch == 'W')
            y--;
        else if(ch == 'z' || ch == 'Z')
            y++;
        else if (ch == 's' || ch == 'S')
            x++;
        else if(ch == 'a' || ch == 'A')
            x--;
        
        if(x == foodx && y == foody){
            score += 10;
            foodx = rand() % (b - 2) + 1;
            foody = rand() % (l- 2) + 1;
        }
        
        if( x== 0 || x == b-1 || y == 0 || y == l-1){
            system("clear");
            printf("GAME OVER\n");
            printf("Final Score: %d",score);
            break;
        }
   
    }
    return 0;
   
}