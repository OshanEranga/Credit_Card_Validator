#include <cs50.h>  // This is the cs50 library
#include <stdio.h> // This is the standard input and output library

// introduce the functions
bool check_sum(long long int credit_num);
int get_remove_digit(long long int integer);
long long int get_remove_last_digit_int(long long int integer);
int digit_count(long long int integer);
bool check_card_visa(long long int card_num);
bool check_card_amex(long long int card_num);
bool check_card_mastercard(long long int card_num);

// main program
int main(void)
{
    // get the credit card number
    long long int credit_num = get_long("Number: ");

    // check card validation by condition
    // Invald length
    if (digit_count(credit_num) != 13 && digit_count(credit_num) != 15 && digit_count(credit_num) != 16)
    {
        printf("INVALID\n");
    }
    else if (check_sum(credit_num) == 0) // Invalid checksum
    {
        printf("INVALID\n");
    }
    else
    {
        // invalid identifying digits
        if (check_card_visa(credit_num) != 1 && check_card_amex(credit_num) != 1 && check_card_mastercard(credit_num) != 1)
        {
            printf("INVALID\n");
        }
    }
}

// check the card is valid
bool check_sum(long long int credit_num)
{
    int multiply_sum = 0;
    int digit_sum = 0;
    long long int number = credit_num;
    while (true)
    {
        if (number <= 0)
        {
            break;
        }
        digit_sum += get_remove_digit(number);
        number = get_remove_last_digit_int(number);
        int multiply_product = get_remove_digit(number) * 2;
        if (digit_count(multiply_product) == 2)
        {
            for (int x = 0; x < 2; x++)
            {
                multiply_sum += get_remove_digit(multiply_product);
                multiply_product = get_remove_last_digit_int(multiply_product);
            }
        }
        else
        {
            multiply_sum += multiply_product;
        }
        number = get_remove_last_digit_int(number);
    }

    int sum = digit_sum + multiply_sum;
    if (get_remove_digit(sum) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// get last digit from integer
int get_remove_digit(long long int integer)
{
    int value = integer % 10;
    return value;
}

// remove last digit from integer and return integer that was removed last digit of previous integer
long long int get_remove_last_digit_int(long long int integer)
{
    int last_digit = integer % 10;
    long long int value = (integer - last_digit) / 10;
    return value;
}

// get digit count from intrger
int digit_count(long long int integer)
{
    int count = 0;
    long long int number = integer;
    while (true)
    {
        if (number <= 0)
        {
            return count;
        }
        number = get_remove_last_digit_int(number);
        count++;
    }
}

// check the credit card is visa card
bool check_card_visa(long long int credit_num)
{
    long long int number = credit_num;
    int num_len = digit_count(number);

    for (int x = 1; x < num_len; x++)
    {
        number = get_remove_last_digit_int(number);
    }
    if (number == 4 && (num_len == 13 || num_len == 16))
    {
        printf("VISA\n");
        return true;
    }
    else
    {
        return false;
    }
}
// check the credit card is American Express card
bool check_card_amex(long long int card_num)
{
    long long int number = card_num;
    int num_len = digit_count(number);
    for (int x = 2; x < num_len; x++)
    {
        number = get_remove_last_digit_int(number);
    }

    if ((number == 34 || number == 37) && num_len == 15)
    {
        printf("AMEX\n");
        return true;
    }
    else
    {
        return false;
    }
}
// check the credit card is MasterCard
bool check_card_mastercard(long long int card_num)
{
    long long int number = card_num;
    int num_len = digit_count(number);
    for (int x = 2; x < num_len; x++)
    {
        number = get_remove_last_digit_int(number);
    }

    if ((number == 51 || number == 52 || number == 53 || number == 54 || number == 55 || number == 22) && num_len == 16)
    {
        printf("MASTERCARD\n");
        return true;
    }
    else
    {
        return false;
    }
}
