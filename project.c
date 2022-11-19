#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 Funtion 1
 This function will print the 
 user guide which will help the user
 */
void user_guide(){
    printf( "\n" ) ; 
    printf( "Enter 1 : to convert a number in one base to any other base \n" ) ;
    printf( "Enter 2 : to multiply two numbers of any base \n" ) ;
    printf( "Enter 3 : to divide two numbers of any base \n" ) ; 
    printf( "Enter 4 : to add two numbers of any base \n" ) ;
    printf( "Enter 5 : to subtract two numbers of any base \n" ) ;
    printf( "Enter 6 : to find the complement of the number in any base \n" ) ;
    printf( "Enter 7 : to find the value of any number in any base raised to some power \n" ) ;
    printf( "Enter 8 : to find the modulo of any division \n" ) ;
    printf( "Enter 9 : \n" ) ;
    printf( "Enter 10 : \n" ) ;

}

int main(){

    user_guide() ;

    return 0 ;
}