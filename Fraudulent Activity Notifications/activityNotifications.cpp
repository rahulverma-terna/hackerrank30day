#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the activityNotifications function below.

void sort(int arr[], int n) 
{ 
   
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
int median(int* expenditure, int d,int i)
{
     int j,c=0;
     int *arr=(int *)malloc(sizeof(int)*d);
     //printf("\n %d\n",c);
    sort(expenditure,i+d);
    
    if((d)%2!=0)
    {
        //printf("%d ",arr[c/2]);
        //return arr[c/2];
        return expenditure[(d+i)/2];
    }
    else
    {
      //printf("%d ",arr[(c)/2]+ arr[((c-1)/2)]/ 2);
      //return (arr[(c)/2]+ arr[((c-1)/2)]/ 2);
      return (expenditure[(d+i)/2]+ expenditure[((d+i-1)/2)]/ 2);
    
    } 
}
int activityNotifications(int expenditure_count, int* expenditure, int d) {
    int i,count=0,m;
for(i=0;i<expenditure_count-d;i++)
{
    //c++;
    m=median(expenditure,d,i);
   // printf("%d ",m);
    if(expenditure[i+d]>=2*m)
       count++;
}
return count++;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nd = split_string(readline());

    char* n_endptr;
    char* n_str = nd[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* d_endptr;
    char* d_str = nd[1];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char** expenditure_temp = split_string(readline());

    int* expenditure = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* expenditure_item_endptr;
        char* expenditure_item_str = *(expenditure_temp + i);
        int expenditure_item = strtol(expenditure_item_str, &expenditure_item_endptr, 10);

        if (expenditure_item_endptr == expenditure_item_str || *expenditure_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(expenditure + i) = expenditure_item;
    }

    int expenditure_count = n;

    int result = activityNotifications(expenditure_count, expenditure, d);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
