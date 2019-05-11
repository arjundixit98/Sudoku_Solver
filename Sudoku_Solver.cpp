//DATA STRUCTURES PROJECT TO SOLVE 9X9 SUDOKU BY FASTEST MEANS POSSIBLE 
 
 

 


#include<stdio.h> 
int check_input(int [][9]); 

int Solve( int [][9]); 	 
	 	 	 	 	 	 	 

//TO SOLVE THE SUDOKU (RECURSIVE FUNCTION ) 

int Unassigned(int [][9],int &,int &);                      
//RETURNS THE INDICES OF EMPTY CELL 

int CheckRow(int [][9],int ,int);                           
//CHECKS THE NUMBER FOR DUPLICACY IN THE RESPECTIVE ROW 

int CheckColumn(int [][9],int,int);                         
//CHECKS THE 
NUMBER FOR DUPLICACY IN THE RESPECTIVE COLUMN 

int CheckBox(int [][9],int,int,int);                        
//CHECKS THE DUPLICACY OF NUMBERS IN 3x3 

int Check(int [][9],int,int,int);                           
//CHECKS THAT NONE 
OF THE ABOVE 3 RULES VIOLATE 

void printGrid(int [][9]); 
 
 
 
 


int main() 

{  
int i,j; 
 
int A[9][9]={{8,0,0,0,0,0,0,0,0},{0,0,3,6,0,0,0,0,0},{0,7,0,0,9,0,2,0,0},{0,5,0,0,0,7,0,0,0},
              {0,0,0,0,4,5,7,0,0},{0,0,0,1,0,0,0,3,0},{0,0,1,0,0,0,0,6,8},{0,0,8,5,0,0,0,1,0},{0,9,0,0,0,0,4,0,0}};

printf("----------------------------------------------------------WELCOME 
TO SUDOKU SOLVER----------------------------------------------------------------------\n"); 

printGrid(A); 
   
	if(check_input(A)==1) 
   
	{ 

	printf("\n   Solution:\n\n");  
 	if(Solve(A)==1)  
	printGrid(A); 
 
 
	else  
	printf("\n No solution exists"); 
 
   
	} 
    

   
	else 
   
	{ 
    	
	printf("\n We are Sorry, the Grid you have provided doesn't 
follow the rules of Sudoku!\nTry Another One!"); 
   
	} 
 
 
 

} 
 


int check_input(int G[9][9]) 

{ 
 
 	int row=9,column=9,p,q; 

	int j,check_row=1,check_box=1,check_column=1; 
 
	for(p=0;p<9;p++) 
 		
	{ 
   
		for(q=0;q<9;q++) 
   
		{ 
    	  
			check_row=1; 
 
			for(j=0;j<9;j++) 
 
			{ 
 
				if(G[row][j]==G[p][q]) 
 
				{
		 
 			check_row=0;  
		  			break; 
 
				}  
 
			}   
			int i; 
 
			check_column=1;  

			for(i=0;i<9;i++) 
 
			{ 
 
				if(G[i][column]==G[p][q]) 
 
				{ 
 
					check_column=0;  
					break; 

				} 
 
			}  
   
    
			check_box=1;     
			int startrow=row-row%3;  
			int startcolumn=column-column%3; 
 

			for(i=0;i<3;i++) 
 
			{ 
 
				for(j=0;j<3;j++) 
 
				{ 
 	
					if(G[i+startrow][j+startcolumn]==G[p][q]) 
 		
					{ 
 	 	
						check_box=0;  	 	
						break; 
 		
					} 
    
				} 

 
			} 
 
 
		} 

	} 
 
 
	
	if(check_row==1 &&check_column==1 &&check_box==1)  
	return 0;  
	else 
return 1; 
 
 
  
 
} 




int Solve(int G[9][9])                //SOLVES THE SUDOKU BY BACKTRACKING 

{ 
 
	int row,column,num; 
 
	if(!Unassigned(G,row,column))         //RETURNS THE EMPTY CELL , IF IT EXISTS , FILL IN ALL THE 9 POSSIBILTIES AND CHECK FOR DUPLICACY USING CHECK() FUNCTION  
	return 1; 
 
 
	
	for(num=1;num<=9;num++ ) 
 
	{ 
 
        
		if (Check(G, row, column, num)) 
        
		{ 
           
         
   		G[row][column] = num; 
            
          
  
             
 
           	if (Solve(G))           //IF WITH THE EXISTING POSSIBILTY , THE 
GRID IS STILL SOLVABLE MEANS WE HAVE REACHED OUR SOLUTION RECURSIVELY 
               
 			return 1; 
  
             

            	G[row][column] = 0;        //IF NOT, CHANGE THAT NUMBER 
AGAIN TO 0 AND CHECK FOR NEXT POSSIBILTY 
       
 		} 
  
	} 
 
	return 0; 
          
}



int Unassigned(int G[9][9],int &row,int &column)   //RETURNS THE ROW AND COLUMN OF THE BLANK CELL WHICH IS FILLED IN BY THE SOLVE() FUNTION 

{  
	int i,j; 

 	for(i=0;i<9;i++) 

 	{ 
 
		for(j=0;j<9;j++) 

 		{ 
 	
			if(G[i][j]==0) 
 	
			{  	 
				row=i;  	
 				column=j;  	 
				return 1;
 
 			} 
 	
 
 		}
 
 	} 

 	return 0; 

} 




int Check(int G[9][9],int row,int column,int num) 

{ 

 	if(CheckRow(G,row,num)&&CheckColumn(G,column,num)&&Che
ckBox(G,row-row%3,column-column%3,num))  
		return 1;  
	else 
 		return 0; 

} 




int CheckRow(int G[9][9],int row,int num)                           //CHECKS 
THE NUMBER FOR DUPLICACY IN THE RESPECTIVE ROW 

{  
	int j; 
 
	for(j=0;j<9;j++) 

 	{ 

 		if(G[row][j]==num)  
			return 0; 

  	} 
 
	return 1; 

} 




int CheckColumn(int G[9][9],int column,int num)        
//CHECKS THE NUMBER FOR DUPLICACY IN THE RESPECTIVE COLUMN 

{
  	int i;
 
 	for(i=0;i<9;i++)
 
 	{ 

 		if(G[i][column]==num)
  			return 0; 
  	} 

 	return 1;
}



int CheckBox(int G[9][9],int startrow,int startcolumn,int num)   
//CHECKS THAT NONE OF THE ABOVE 3 RULES VIOLATE BY CALLING CHECKROW(), CHECKCOLUMN() AND CHECKBOX() 

{  
	int i,j; 
 
	for(i=0;i<3;i++) 

 	{ 

 		for(j=0;j<3;j++) 

 		{ 
 
			if(G[i+startrow][j+startcolumn]==num)
  				return 0; 
 
   		} 
 
	}
 
 	return 1;
}
 
 

void printGrid(int G[9][9]) 		

{ 
 
	int row,col,k;  printf(" -----------------------\n");     
	for (row = 0; row < 9; row++) 
   
 	{ 
     

       		for (col = 0; col < 9; col++) 
    
   		{ 
     
      			if(col==0)     
       				printf("| ");      
        			printf("%d ", G[row][col]); 
              
			if(col==8 || col==2 || col==5)       
     				printf("| "); 
  
    		} 
   
     		printf("\n");       
    		if(row==2 || row==5||row==8) 
  
      		printf(" -----------------------\n"); 
  
  	}
 
} 
 
 
