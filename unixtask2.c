#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int main() {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) { //retrieving the current directory
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   struct dirent *dp;
    DIR *dir = opendir(cwd);
    char str[100],old_name[100],new_name[100];
    int files=0;
    int value;

    // Unable to open directory stream
    if (!dir)
        printf("Directory doesn't exist\n");

    while ((dp = readdir(dir)) != NULL)
    {

	    for(int i=0;i<100;i++)
	    {
               str[i]='\0';

             }
         for(int i=0;i<100;i++)
        {
           old_name[i]='\0';
           new_name[i]='\0';
        }
        strcpy(str,dp->d_name);//storing the filename in the variable old_name
        strcpy(old_name,str);


	   int k = 0;
	   while (str[k])//code to replace whitespaces with underscores
	 {
		if (str[k] == ' ')
                    str[k]='_';
		k++;
	 }
	str[k] = '\0';


    strcpy(new_name,str);//storing the new name of the file in the variable new_name
    puts(old_name);
    puts(new_name);

      value = rename(old_name,new_name);//renaming the current file 

    // Print the result
    if(!value)
    {
        printf("%s", "File name changed successfully");
	printf("\n");
    }
    else
    {
        perror("Error");
    }



    }

    // Close directory stream
    closedir(dir);
  
   return 0;
}
