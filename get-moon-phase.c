#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Compile with 'gcc get-moon-phase.c -lm -o get-moon-phase.o'
int main(int argc, char *argv[]) {

  if(argv[1] != NULL && !strcmp(argv[1], "--help") || argv[2] != NULL && !strcmp(argv[2], "--help") || argv[3] != NULL && !strcmp(argv[3], "--help")) {
    printf("Usage:\n");
    printf("--age      print only the current moon age\n");
    printf("--phase    print only the current moon phase\n");
    printf("--help     print this help\n");
    return 0;
  }

  const double lunarDays = 29.53058770576;
  const double lunarSeconds = lunarDays * 24 * 60 * 60;

  unsigned long currentDate = (unsigned long) time(NULL);
  double newMoon2000 = 947182440;

  double elapsedSeconds = currentDate - newMoon2000;

  double currentSeconds = remainder(elapsedSeconds, lunarSeconds);

  if(currentSeconds < 0){
    currentSeconds += lunarSeconds;
  }
  
  double currentFraction = currentSeconds / lunarSeconds; //Percentage of Lunation
  double currentDays = currentFraction * lunarDays; //Moon age

  if(argc == 1 || argv[1] != NULL && !strcmp(argv[1], "--age") || argv[2] != NULL && !strcmp(argv[2], "--age")) {
    printf("%f\n", currentDays);
  }

  if(argc == 1 || argv[1] != NULL && !strcmp(argv[1], "--phase") || argv[2] != NULL && !strcmp(argv[2], "--phase")) { 
    if(currentDays >= 0 && currentDays < 1){
      printf("New\n");
    } else if(currentDays >= 1 && currentDays < 6.38264692644001){
      printf("Waxing Crescent\n");
    } else if(currentDays >= 6.38264692644001 && currentDays < 8.38264692644){
      printf("First Quarter\n");
    } else if(currentDays >= 8.38264692644 && currentDays < 13.76529385288){
      printf("Waxing Gibbous\n");
    } else if(currentDays >= 13.76529385288 && currentDays < 15.76529385288){
      printf("Full\n");
    } else if(currentDays >=  15.76529385288 && currentDays < 21.14794077932){
      printf("Waning Gibbous\n");
    } else if(currentDays >= 21.14794077932 && currentDays < 23.14794077932){
      printf("Third Quarter\n");
    } else if(currentDays >= 23.14794077932 && currentDays < 28.53058770576){
      printf("Waning Crescent\n");
    } else if(currentDays >= 28.53058770576 && currentDays < 29.53058770576){
      printf("New\n");
    }
  }

  
  return 0;
}
