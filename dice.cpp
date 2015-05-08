#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/* Author:	Matt W. Martin, 4374851
 *		kaethis@tasmantis.net
 */

void rollDie(int &die){
/* This function simulates a single roll of a die by generating a random number
 * between one and six and assigning it to the INT. */

	die = (rand() % 6 + 1);
}

void drawDice(int die0, int die1){
/* This function draws two ASCII dice according to what two INT values are passed to
 * it and prints them to the console. */
	 
	/* 			  D I E - A G R A M
	 * ---------------------------------------------------------------
	 *		        1		 	       1
	 * _____________0123456789012345_________________0123456789012345_
	 * ascii0[0] =     B   S i d e A    ascii1[0] =    .-------.      
	 * ascii0[1] =    e .--------.      ascii1[1] =   / o o o / \     
         * ascii0[2] =   d / \  o o o \     ascii1[2] =  / o o o / x \    
	 * ascii0[3] =  i / x \  o o o \    ascii1[3] =   o o o / x x \   
	 * ascii0[4] = S / x x \  o o o     ascii1[4] =  \-----. x x x .  
         * ascii0[5] =  . x x x .-------    ascii1[5] =  .x x x \ x x /   
         * ascii0[6] =   \ x x / x x x /    ascii1[6] =  \ x x x \ x /    
	 * ascii0[7] =    \ x / x x x /     ascii1[7] =   \ x x x \ /     
	 * ascii0[8] =     \ / x x x /
	 *		     S i d e C
	 *
	 *	NOTE: SideA indicates the significant face of the die.   */
	
	char  ascii0[9][17] =	{"                ", 
				 "    .--------.  ",
        			 "   / \\        \\ ", 
				 "  /   \\        \\",
				 " /     \\        ", 
				 ".       .-------",
        			 " \\     /       /", 
				 "  \\   /       / ",
				 "   \\ /       /  "};

	char ascii1[9][17] =	{"  .-------.     ", 
				 " /       / \\    ",
				 "/       /   \\   ", 
				 "       /     \\  ",
				 "\\-----.       . ", 
				 ".      \\     /  ",
				 "\\       \\   /   ", 
				 " \\       \\ /    "};
	
	/* The following SWITCHes apply the dots to the corresponding dice faces by
	 * modifying CHARs in the ARRAYs according to which values were passed to
	 * die0 and die1, respectively. */

	switch(die0){

		case 1:	
	   /* Side A */ ascii0[3][11] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[5][4]  ='x'; ascii0[7][4]  ='x';
	  		ascii0[5][2]  ='x'; ascii0[5][6]  ='x'; 
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[6][13] ='x'; ascii0[8][7]  ='x';
			ascii0[8][11] ='x';
			break;

		case 2:	
	   /* Side A */ ascii0[2][8]  ='o'; ascii0[4][14] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[5][2]  ='x'; ascii0[5][6]  ='x';
	  		ascii0[7][4]  ='x';
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[6][11] ='x'; ascii0[6][13] ='x';
			ascii0[8][7]  ='x'; ascii0[8][9]  ='x'; ascii0[8][11] ='x';
			break;
	
		case 3:
	   /* Side A */	ascii0[2][8]  ='o'; ascii0[3][11] ='o'; ascii0[4][14] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[4][3]  ='x'; ascii0[5][2]  ='x';
			ascii0[5][6]  ='x'; ascii0[6][5]  ='x'; ascii0[7][4]  ='x';
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[7][10] ='x'; ascii0[8][11] ='x';
			ascii0[6][13] ='x'; ascii0[8][7]  ='x';
			break;

		case 4:	
	   /* Side A */ ascii0[2][8]  ='o'; ascii0[2][12] ='o'; ascii0[4][10] ='o';
			ascii0[4][14] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[5][2]  ='x'; ascii0[5][4]  ='x';
			ascii0[5][6]  ='x'; ascii0[7][4]  ='x';
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[7][8]  ='x'; ascii0[8][7]  ='x';
			ascii0[6][13] ='x'; ascii0[7][12] ='x'; ascii0[8][11] ='x';
			break;

		case 5:	
	   /* Side A */ ascii0[2][8]  ='o'; ascii0[2][12] ='o'; ascii0[3][11] ='o';
			ascii0[4][10] ='o'; ascii0[4][14] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[4][5]  ='x'; ascii0[5][6]  ='x';
			ascii0[5][2]  ='x'; ascii0[6][3]  ='x'; ascii0[7][4]  ='x';
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[6][13] ='x'; ascii0[8][7]  ='x';
			ascii0[8][11] ='x';
			break;

		case 6:	
	   /* Side A */ ascii0[2][8]  ='o'; ascii0[2][10] ='o'; ascii0[2][12] ='o';
			ascii0[4][10] ='o'; ascii0[4][12] ='o'; ascii0[4][14] ='o';
	   /* Side B */ ascii0[3][4]  ='x'; ascii0[5][2]  ='x'; ascii0[5][6]  ='x';
			ascii0[7][4]  ='x';
	   /* Side C */ ascii0[6][9]  ='x'; ascii0[6][13] ='x'; ascii0[7][10] ='x';
			ascii0[8][7]  ='x'; ascii0[8][11] ='x';
			break;
	}

	switch(die1){

		case 1:	
	   /* Side A */ ascii1[2][4]  ='o';
	   /* Side B */ ascii1[2][10] ='x'; ascii1[4][10] ='x'; ascii1[6][10]  ='x';
	   /* Side C */ ascii1[5][1]  ='x'; ascii1[7][7]  ='x';
			break;

		case 2:	
	   /* Side A */ ascii1[1][7]  ='o'; ascii1[3][1]  ='o';
	   /* Side B */ ascii1[4][10] ='x';
	   /* Side C */ ascii1[5][1]  ='x'; ascii1[6][4]  ='x'; ascii1[7][7]  ='x';
			break;
	
		case 3:
	   /* Side A */	ascii1[1][7]  ='o'; ascii1[2][4]  ='o'; ascii1[3][1]  ='o';
	   /* Side B */ ascii1[3][10] ='x'; ascii1[6][10] ='x';
	   /* Side C */ ascii1[6][4]  ='x';
			break;

		case 4:
	   /* Side A */ ascii1[1][3]  ='o'; ascii1[1][7]  ='o'; ascii1[3][1]  ='o';
			ascii1[3][5]  ='o';
	   /* Side B */ ascii1[4][10] ='x';
	   /* Side C */ ascii1[5][5]  ='x'; ascii1[7][3]  ='x';
			break;

		case 5:
	   /* Side A */ ascii1[1][3]  ='o'; ascii1[1][7]  ='o'; ascii1[2][4]  ='o';
			ascii1[3][1]  ='o'; ascii1[3][5]  ='o';
	   /* Side B */ ascii1[6][4]  ='x'; 
	   /* Side C */ ascii1[4][8]  ='x'; ascii1[4][10] ='x'; ascii1[4][12] ='x';
			break;

		case 6:	
	   /* Side A */ ascii1[1][3]  ='o'; ascii1[1][7]  ='o'; ascii1[2][2]  ='o';
			ascii1[2][6]  ='o'; ascii1[3][1]  ='o'; ascii1[3][5]  ='o';
	   /* Side B */ ascii1[4][8]  ='x'; ascii1[4][12] ='x';
	   /* Side C */ ascii1[5][5]  ='x'; ascii1[6][4]  ='x'; ascii1[7][3]  ='x';
			break;
	}
	
	for(int i = 0; i < 9; i++)
			cout << "	" << ascii0[i] << ascii1[i] << endl;

	cout << endl;
}

int main(){

	int  die0, die1;

	srand(time(NULL));

	rollDie(die0);
	rollDie(die1);

	drawDice(die0, die1);

	return 0;
}
