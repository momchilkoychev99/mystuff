#include <stdio.h>
#include <cs50.h>

long cal_next_digit (long a, long b);
long remaining_card_number (long a, long b);
long multiply (long a);
long sum_product_digits (long a);

int main (void)
{
    // identifying each digit from the card number
    long card_number = get_long("Type in your credit card number: ");
    long last_digit = card_number % 10;
    long second_tolast_digit = cal_next_digit(card_number, last_digit);
    long n = remaining_card_number(card_number, last_digit);
    long third_tolast_digit = cal_next_digit(n, second_tolast_digit);
    long m = remaining_card_number(n, second_tolast_digit);
    long fourth_tolast_digit = cal_next_digit(m, third_tolast_digit);
    long k = remaining_card_number(m, third_tolast_digit);
    long fifth_tolast_digit = cal_next_digit(k, fourth_tolast_digit);
    long o = remaining_card_number(k, fourth_tolast_digit);
    long sixth_tolast_digit = cal_next_digit(o, fifth_tolast_digit);
    long p = remaining_card_number(o, fifth_tolast_digit);
    long seventh_tolast_digit = cal_next_digit(p, sixth_tolast_digit);
    long j = remaining_card_number(p, sixth_tolast_digit);
    long eigth_tolast_digit = cal_next_digit(j, seventh_tolast_digit);
    long f = remaining_card_number(j, seventh_tolast_digit);
    long ninth_tolast_digit = cal_next_digit(f, eigth_tolast_digit);
    long r = remaining_card_number(f, eigth_tolast_digit);
    long tenth_tolast_digit = cal_next_digit(r, ninth_tolast_digit);
    long a = remaining_card_number(r, ninth_tolast_digit);
    long eleventh_tolast_digit = cal_next_digit(a, tenth_tolast_digit);
    long b = remaining_card_number(a, tenth_tolast_digit);
    long twelfth_tolast_digit = cal_next_digit(b, eleventh_tolast_digit);
    long g = remaining_card_number(b, eleventh_tolast_digit);
    long thirteenth_tolast_digit = cal_next_digit(g, twelfth_tolast_digit);
    long q = remaining_card_number(g, twelfth_tolast_digit);
    long fourteenth_tolast_digit = cal_next_digit(q, thirteenth_tolast_digit);
    long h = remaining_card_number(q, thirteenth_tolast_digit);
    long fifteenth_tolast_digit = cal_next_digit(h, fourteenth_tolast_digit);
    long y = remaining_card_number(h, fourteenth_tolast_digit);
    long sixteenth_tolast_digit = cal_next_digit(y, fifteenth_tolast_digit);

    // multiplying every other digit by 2
    long multi_secondtolast = multiply(second_tolast_digit);
    long multi_fourthtolast = multiply(fourth_tolast_digit);
    long multi_sixthtolast = multiply(sixth_tolast_digit);
    long multi_eigthtolast = multiply(eigth_tolast_digit);
    long multi_tenthtolast = multiply(tenth_tolast_digit);
    long multi_twelfthtolast = multiply(twelfth_tolast_digit);
    long multi_fourteenthtolast = multiply(fourteenth_tolast_digit);
    long multi_sixteenthtolast = multiply(sixteenth_tolast_digit);

    // Figuring out the sum of each of the products' digits
    long sum_multi_secondtolast = sum_product_digits(multi_secondtolast);
    long sum_multi_fourthtolast = sum_product_digits(multi_fourthtolast);
    long sum_multi_sixthtolast = sum_product_digits(multi_sixthtolast);
    long sum_multi_eigthtolast = sum_product_digits(multi_eigthtolast);
    long sum_multi_tenthtolast = sum_product_digits(multi_tenthtolast);
    long sum_multi_twelfthtolast = sum_product_digits(multi_twelfthtolast);
    long sum_multi_fourteenthtolast = sum_product_digits(multi_fourteenthtolast);
    long sum_multi_sixteenthtolast = sum_product_digits(multi_sixteenthtolast);

    // the sum of the products' digits / the sum of the digits that weren't multiplied by 2 / the total sum
    long sum_everyotherdigit = sum_multi_secondtolast + sum_multi_fourthtolast + sum_multi_sixthtolast + sum_multi_eigthtolast + sum_multi_tenthtolast + sum_multi_twelfthtolast + sum_multi_fourteenthtolast + sum_multi_sixteenthtolast;
    long sum_everydigit = last_digit + third_tolast_digit + fifth_tolast_digit + seventh_tolast_digit + ninth_tolast_digit + eleventh_tolast_digit + thirteenth_tolast_digit + fifteenth_tolast_digit;
    long allsum = sum_everyotherdigit + sum_everydigit;

    // check if checksum is 0
    if (allsum % 10 == 0)
    {
        // check for length
        int card_length = 0;
        while (card_number > 0)
        {
            card_length++;
            card_number /= 10;
        }

        switch(card_length)
        {
            case 16:
                if (sixteenth_tolast_digit == 5)
                {
                    if (fifteenth_tolast_digit == 1 || fifteenth_tolast_digit == 2 || fifteenth_tolast_digit == 3 || fifteenth_tolast_digit == 4 || fifteenth_tolast_digit == 5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else if (sixteenth_tolast_digit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 15:
                if (fifteenth_tolast_digit == 3)
                {
                    if (fourteenth_tolast_digit == 4 || fourteenth_tolast_digit == 7)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                    printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 13:
                if (thirteenth_tolast_digit == 4)
                {
                    printf("Visa\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}




long cal_next_digit (long a, long b)
    {
        // a = card_number, b = last digit
        int result = ((a - b) / 10) % 10;
        return result;
    }

long remaining_card_number (long a, long b)
    {
        long result = (a - b) / 10;
        return result;
    }

long multiply (long a)
    {
        long b = a * 2;
        return b;
    }

    /*
    Figuring out the sum of each of the products' digits.
    First, I'm getting the remainder % 10. So if the multiplied is 12. I get the 2nd digit which is 2. If it's 6, I get 6.
    So, how do I get the 1st digit? Here's how: (12 - (12 % 10)) % 10
    If it's a single digit, the first digit will be 0.
    Then, I do the sum of the 1st and 2nd digit.
    */
long sum_product_digits (long a)
    {
        long b = (a % 10) + ((a - (a % 10)) / 10);
        return b;
    }