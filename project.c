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

/*
Funtion 2
This function will return the numerical
value of the character received 
by the function
*/
int value_of_character (char c){
    if ( c >= '0' && c <= '9' ){
        return (int)c - '0' ;
    } else if ( c >= 'a' && c <= 'z' ){
        return (int)c - 'a' + 10 ;
    } else{
        return (int)c - 'A' + 10 ;
    }
}
 
/*
Funtion 3
This function will convert a number 
from any base to decimal
*/
int convert_to_decimal ( char *str , int base ){
    int len = strlen( str ) ;
    int power = 1 ; // Initialize power of base
    int to_decimal = 0 ;  // Initialize result
 
    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1 ; i >= 0 ; i--){
        // A digit in input number must be
        // less than number's base

        if (value_of_character(str[i]) >= base){
           printf( "Invalid Number" ) ;
           return -1 ;
        }
 
        to_decimal += value_of_character(str[i]) * power ;
        power = power * base ;
    }

    return to_decimal ;
}

/*
Function 4
This function will return the
the character associated with the 
number received by it
*/
char return_character(int num){
    if ( num >= 0 && num <= 9 ){
        return (char)( num + '0' ) ;
    } else if ( num >= 'a' && num <= 'z' ){
        return (char)( num - 10 + 'a' ) ;
    } else{
        return (char)( num - 10 + 'A' ) ;
    }
}

/*
Function 5
This function will reverse an array
*/
void reverse_string( char *str ){

    int len = strlen( str ) ;

    for ( int i = 0; i < len/2; i++ ){
        char temp = str[i] ;
        str[i] = str[len-i-1] ;
        str[len-i-1] = temp ;
    }
}

/*
function 6
This function will convert any number
from decimal to any base 
*/
char* convert_from_decimal( char *res , int base , int inputNum ){
    int index = 0 ;  // Initialize index of result
 
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while ( inputNum > 0 ){
        res[index] = return_character( inputNum % base ) ;
        inputNum /= base ;
        index++ ;
    }
 
    res[index] = '\0' ;

    // Reverse the result
    reverse_string(res) ;
 
    return res ;
}

/*
Function 7
This function will multiply two numbers
of any base
*/
void multiplier( char* x , char* y , int base ){

    int num_1 = convert_to_decimal( x , base ) ;
    int num_2 = convert_to_decimal( y , base ) ;

    int result = num_1 * num_2 ;

    char new_string[100] ;

    convert_from_decimal( new_string , base , result ) ;
    printf( "The result is : %s \n" , new_string ) ;

}

/*
Function 8
This function will divide two numbers
of any base
*/
void divide( char* x , char* y , int base ){

    int num_1 = convert_to_decimal( x , base ) ;
    int num_2 = convert_to_decimal( y , base ) ;

    int result = num_1 / num_2 ;

    char new_string[100] ;
    convert_from_decimal( new_string , base , result ) ;
    printf( "The result is : %s \n" , new_string ) ;

}

/*
Function 9
This function will add two numbers
of any base
*/
void addition( char* x , char* y , int base ){

    int num_1 = convert_to_decimal( x , base ) ;
    int num_2 = convert_to_decimal( y , base ) ;

    int result = num_1 + num_2 ;

    char new_string[100] ;

    convert_from_decimal( new_string , base , result ) ;
    printf( "The result is : %s \n" , new_string ) ;

}

/*
Function 10
This function will subtract two numbers
of any base
*/
void subtraction( char* x , char* y , int base ){

    int num_1 = convert_to_decimal( x , base ) ;
    int num_2 = convert_to_decimal( y , base ) ;

    int result = num_1 - num_2 ;

    char new_string[100] ;

    convert_from_decimal( new_string , base , result ) ;
    printf( "The result is : %s \n" , new_string ) ;

}


int main(){

    char string_of_digits[100] ;
    char string_of_result[100] ;
    char string_1[100] ;
    char string_2[100] ;
    int initial_base ;
    int final_base ;
    int selector ;
    int num_1 ;

    user_guide() ;

    scanf("%d" , &selector) ;

    switch(selector){
        case 1:

            printf("Enter the number to convert \n");
            scanf("%s", string_of_digits);
            printf("Enter the base of the number \n");
            scanf("%d", &initial_base);
            printf("Enter the base to which you want to convet the number in \n");
            scanf("%d", &final_base);

            int decimal_value = convert_to_decimal(string_of_digits , initial_base);

            convert_from_decimal( string_of_result , final_base , decimal_value);

            printf("The equivalent of %s in the base %d is %s " , string_of_digits , final_base , string_of_result );
            break ;

        case 2:
            
            printf("Enter the base of numbers \n") ;
            scanf( "%d" , &initial_base ) ;
            printf("Enter the numbers \n") ;
            scanf( "%s%s" , string_1 , string_2 ) ;

            multiplier( string_1 , string_2 , initial_base ) ;
            break ;

        case 3:

            printf( "Enter the base of numbers \n ") ;
            scanf("%d" , &initial_base ) ;
            printf("Enter the divident \n" ) ;
            scanf("%s" , string_1 ) ;
            printf("Enter the divisor \n" ) ;
            scanf("%s" , string_2 ) ;

            divide( string_1 , string_2 , initial_base ) ;
            break ;

        case 4:

            printf( "Enter the base of numbers \n " ) ;
            scanf("%d" , &initial_base ) ;
            printf( "Enter the numbers \n " ) ;
            scanf("%s%s" , string_1 , string_2 ) ;

            addition( string_1 , string_2 , initial_base ) ;
            break ;

        case 5:

            printf( "Enter the base of numbers \n " ) ;
            scanf("%d" , &initial_base ) ;
            printf( "Enter the numbers \n " ) ; 
            scanf("%s%s" , string_1 , string_2 ) ;

            subtraction( string_1 , string_2 , initial_base ) ;
            break ;
        
    }

    return 0 ;
}