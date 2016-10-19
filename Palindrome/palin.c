//Nerys Jimenez Pichardo
//Lab 10

//wc -w --- 479,623 words

#include <stdio.h>
#include <string.h>
#include <time.h>
void reverse_str (char *str);
long int dict_size = 500000;
char dictionary[500000][45];

int main (int argc, char *argv []) 
{
  FILE *fr;
  FILE *fw;
  int lower = 0;
  int p = 0;

  //counter of pali words
  long int pali_count = 0;

  //used in nested for loops
  long int i = 0;
  long int j = 0;
  
  //counter--how many lowercase words contains the array
  long int count = 0;
  
  //used to read words from the file
  char word[45];
  
  //used to reverse words from the array
  char str[45];
  
  //used to check for the end of the file
  char c;

  //stores processor time
  clock_t start_t;
  clock_t end_t;
  double total_t;
  
  fr = fopen("/usr/share/dict/words", "r");
  fw = fopen("newDic.txt", "w+");
  
  c = fscanf(fr, "%s", word);

  /* reads the given file and stores the lowercase letters in a new file and in a 2D array a*/
  while(c != EOF)
  {
    for(p = 0; word[p] !='\0'; ++p)
    {
      if(word[p] >= 'a' && word[p] <= 'z')
      {
	lower = 1;
      }
      else
      {
	lower = 0;
	break;
      }
    }
    if(lower > 0)
    {
      fprintf(fw, "%s \n", word);
      strcpy(dictionary[i], word);
      ++i;
      ++count;
    }
    
    c = fscanf(fr, "%s", word);
  }
  
  //clock starts running
  start_t = clock();

  /* searches for all palindromic matches in the array */
  for(i = 0; i < count; ++i)
  {
    strcpy(str, dictionary[i]);
    reverse_str(str);
    
    for(j = i; j < count; ++j)
    {
      if(strcmp(str, dictionary[j]) == 0)
      {
	++pali_count;
	break;
      }
    }
  }
  
  //clock stops 
  end_t = clock();

  /*calculates the total time the processor takes to find all the palindromic matches */
  total_t = (double)(end_t - start_t)/(double)(CLOCKS_PER_SEC);
  
  //prints out the total palindromic matches and time taken 
  printf("Total time taken in seconds: %f \n", total_t);
  printf("%d Palindromic matches \n", pali_count);
 
  //closes the files
  fclose(fr);
  fclose(fw);
  
  //end of program
  return 0;

}

/* reverse string method */
void reverse_str(char *str)
{
  char *start = str;
  char *end = start + strlen(str) -1;
  char temp;

  while (end > start)
  {
    temp = *start;
    *start = *end;
    *end = temp;
    ++start;
    --end;
  }
  
}
