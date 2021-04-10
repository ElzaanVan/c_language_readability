#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string word);
int count_words(string word);
int count_sentences(string word);


int main(void)
{
    string text = get_string("Text:");
    int letters = count_letters(text);
    // printf("%i\n", letters);
    int words = count_words(text);
    // printf("%i\n", words);
    int sentences = count_sentences(text);
    // printf("%i\n", sentences);

    //Coleman-Liau index
    float L = letters * 100 / words;

    float S = sentences * 100 / words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);


    // printf("%i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Counting Letters
int count_letters(string word)
{
    //Set up to count letters
    int score = 0;
    int i;
    int n = strlen(word);
    int spaces = 0;
    int letter = 0;
    int punct = 0;

    //Counts each character
    for (i = 0; i < n; i++)
    {
        //CS50 manual pages
        char c = word[i];
        //Check only for alphabetical characters
        if (isalpha(c))
        {
          if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
          {
            score = i + 1;
          }
        }
    }

    //Counts white spaces
    for (i = 0; i < score; i++)
    {
        if (word[i] == 32)
        {
            spaces++;
        }
    }

    //Counts punctuation
    for (i = 0; i < score; i++)
    {
        if (ispunct(word[i]))
        {
            punct++;
        }
    }

    letter = score - spaces - punct;
    return letter;
}

//Counting words
int count_words(string word)
{
    int i;
    int n = strlen(word);
    int w = 0;

//Counts words that are separated by spaces
    for (i = 0; i < n; i++)
    {
        if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t')
        {
            w++;
        }
    }

    return (w + 1);
}

//Counting sentences
int count_sentences(string word)
{
    int i;
    int n = strlen(word);
    int s = 0;

//Counts the sentences
    for (i = 0; i < n; i++)
    {
        if (word[i] == '.' || word[i] == '?' || word[i] == '!')
        {
            s++;
        }
    }

    return s;
}