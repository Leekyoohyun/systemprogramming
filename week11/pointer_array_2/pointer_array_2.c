//
// Created by 이규현 on 2024. 12. 5..
//
#include <stdio.h>
#include <stdlib.h>

/*
// ex
int main() {
  int num = 50;
  int arr[10];
  int *p;


  p = &num;
  printf("p = %p\n", p);
  printf("&num = %p\n", &num);
  printf("*p = %d\n", *p);

  return 1;
}
*/

/*
// ex
int main() {
  int *p1;
  char *p2;
  double *p3;

  printf("p1 = %p, p2 = %p, p3 = %p\n", p1, p2, p3);

  printf("p1+1 = %p, p2+1 = %p, p3+1 = %p\n", p1+1, p2+1, p3+1);

}
*/

/*
//ex
int main() {
  int arr[] = {10, 20, 30};

  int *p, num1, num2, num3;

  p = arr;
  num1 = *(++p);
  printf("%d\n", num1);
  p = arr;

  num2 = *(p++);
  printf("%d\n", num2);
  p = arr;

  num3 = ++(*p);
  printf("%d\n", num3);

  return 0;

}
 */

/*
//ex
#define MAX 5
int main() {
  int i, sum, *p, arr[MAX] = {5,10,15,20,25};

  sum = 0;
  for(p = arr; p < &arr[MAX]; p++)
    sum += *p;
  printf("Sum is %d\n", sum);

  sum = 0;
  for(i = 0; i < MAX; i++)
    sum += *(arr+i);
  printf("Sum is %d\n", sum);

  sum = 0;
  p = arr;
  for(i = 0; i < MAX; i++)
    sum += *(p++);
  printf("Sum is %d\n", sum);

  return 1;
}
 */

/*
//ex
#define MAX 6
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <windows.h>

void print_array(const int*, int);
void swap(int*, int*);
void bubble_sort(int*, int);
int is_duplicate(const int*, int, int);
void set_numbers(int*);

void print_array(const int* arr, int length) {
  int i;
  for(i = 0; i < length; i++)
    printf("%d ", arr[i]);
}

void swap(int* p, int* q) {
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

void bubble_sort(int* arr, int length) {
  int pass, current, sorted = 0;
  for(pass = 1; (pass < length) && (!sorted); pass++){
    sorted = 1;
    for(current=0; current < (length - pass); current++){
      if(arr[current] > arr[current+1])
        swap(&arr[current], &arr[current+1]);
      sorted = 0;
    }
  }
}

int main(void) {
  int money, i, lottery[MAX];
  while(1){
    printf("Enter available money: \n");
    scanf("%d", &money);
    if(money == 0)
      break;
    printf("Possible sets of lottery numbers are, \n");
    for(i = 1; i<= money/1000; i++){
      set_numbers(lottery);
      bubble_sort(lottery, MAX);
      print_array(lottery, MAX);
      printf("\n");
    }
  }

  return 0;
}

int is_duplicate(const int* arr, int length, int n){
  int i;
  for(i=0; i<length; i++){
    if(arr[i] == n)
      return 1;
  }

  return 0;
}

*/

// 이중 포잍너

/*
int main() {
  int num = 10;
  int *ptr= &num;
  int **dptr = &ptr;

  printf("num: %d\n", num);
  printf("*ptr: %d\n", *ptr);
  printf("**dptr: %d\n", **dptr);

  return 1;
}

 */

/*
// ex
void swap(int **, int**);
int main() {
  int first, second;
  int *fp = &first, *sp = &second;

  printf("Enter two: \n");
  scanf("%d %d", &first, &second);
  printf("Before swap: *fp: %d *sp: %d\n", *fp, *sp);
  swap(&fp, &sp);
  printf("After swap: *fp: %d *sp: %d\n", *fp, *sp);

  return 1;
}

void swap(int **p1, int **p2) {
  int * temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
*/

//ex
/*
int main() {
  int *p, arr[4] = {10, 20, 30, 40};

  printf("arr: %p\n", arr);
  printf("arr+1: %p\n", arr+1);
  printf("sizeof(*arr): %lu\n\n", sizeof(*arr));

  printf("&arr: %p\n", &arr);
  printf("&arr+1: %p\n", &arr+1);
  printf("sizeof(*(&arr)): %lu.\n\n", sizeof(*(&arr)));

  p = arr;
  printf("p: %p\n", p);
  printf("p+1: %p\n", p+1);
  printf("&p: %p\n", &p);
  printf("&p+1: %p\n", &p+1);

  return 1;
}

 */
/*
#define MAX 10

int* square_array(){
  int i;
  int *p = NULL;

  p = (int*)malloc(MAX * sizeof(int));
  if(p != NULL){
    for(i=0; i< MAX; i++){
      p[i] = i*i;
    }
  }
  return p;
}

int main(){
  int i, *arr = square_array();
  for(i=0; i< MAX; i++)
    printf("%d ", *(arr+i));
  printf("\n");
  free(arr);
  arr = NULL;

  return 1;
}

 */

/*
int main() {
  int *p = (int*)malloc(3 * sizeof(int));
  int i;

  p[0] = 100; p[1] = 200; p[2] = 300;
  p = (int *)realloc(p, 5 * sizeof(int));
  if(p != NULL){
    p[3] = 400;
    p[4] = 500;
  }

  for(i = 0; i < 5; i++){
    printf("%d ", *(p+i));
  }
  printf("\n");

  free(p);
  p = NULL;

  return 0;
}
 */
/*
int main() {
  int last = 0; char ch;
  char *p;

  p = (char *)malloc(sizeof(char));
  if(p == NULL)
    exit(1);

  printf("Enter a character string.\n");
  while(1){
    if((ch = getchar()) == '\n')
      break;
    else{
      *(p+last) = ch;
      last++;
      p = (char*)realloc(p, (last+1)*sizeof(char));
      if(p == NULL)
        exit(1);
    }
  }

  *(p+last) = '\0';
  printf("%s\n", p);

  free(p);
  p = NULL;

  return 1;

}

 */

/*
#define ROW 2
#define COL 3

int main() {
  int i, j;
  int first[ROW][COL], second[ROW][COL], add[ROW][COL];

  for(i = 0; i < ROW; i++){
    for(j = 0; j<COL; j++){
      printf("Enter first matrix[%d][%d]: ", i, j);
      scanf("%d", &first[i][j]);
    }
  }

  for(i = 0; i < ROW; i++){
    for(j = 0; j<COL; j++){
      printf("Enter second matrix[%d][%d]: ", i, j);
      scanf("%d", &second[i][j]);
    }
  }

  for(i = 0; i < ROW; i++){
    for(j = 0; j<COL; j++){
      add[i][j] = first[i][j] + second[i][j];
    }
  }

  printf("Sum of two matrices: \n");
  for(i = 0; i < ROW; i++){
    for(j = 0; j<COL; j++){
      printf("%d ", add[i][j]);
    }
    printf("\n");
  }

  return 1;
}


 */
/*
int main() {
  int *p, *q, arr[2][3] = {1, 2, 3, 4, 5, 6 };

  printf("arr: %p\n", arr);
  printf("arr+1: %p\n", arr+1);
  printf("&arr: %p\n", &arr);
  printf("&arr+1: %p\n\n", &arr+1);

  printf("arr[0]: %p\n", arr[0]);
  printf("arr[0]+1: %p\n", arr[0]+1);
  printf("&arr[0]: %p\n", &arr[0]);
  printf("&arr[0]+1: %p\n\n", &arr[0]+1);

  p = arr;
  printf("p: %p, p+1: %p \n", p, p+1);

  q = arr[0];
  printf("q: %p, q+1: %p \n", q, q+1);

  printf("(q+1)[2]: %d \n\n", (q+1)[2]);

  return 0;
}

 */

void print_it(int p[2][3]){
  int i, j;
  for(i = 0; i < 2; i++){
    for(j = 0; j < 3; j++){
      p[i][j] = i*i+j*j;
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int *arr = (int*)malloc(2*3*sizeof(int));
  if(arr != NULL)
    print_it(arr);
  free(arr);
  arr = NULL;

  return 0;
}