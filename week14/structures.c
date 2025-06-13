//
// Created by 이규현 on 2024. 12. 10..
//

/*
//ex 13-1
//car.h
struct car {
    char name[8];
    int year;
    int mileage;
};

//main.c
#include "car.h"
#include <stdio.h>

int main() {
    struct car mycar = {"sonata", 2015, 120000};

    printf("Name: %s\n", mycar.name);
    printf("Year: %d\n", mycar.year);
    printf("Mileage: %d\n", mycar.mileage);

    printf("&mycar: %p\n", &mycar);
    printf("&(mycar.year): %p\n", &(mycar.year));

    printf("Enter the mileage: \n");
    scanf("%d", &mycar.mileage);
    printf("The new mileage is: %d\n", mycar.mileage);

    if(mycar.mileage > 150000)
        printf("It's old\n");
    else
        printf("It's new\n");
    return 0;
}
 */

/*
//13-2
//point.h
struct point {
    int x;
    int y;
};

struct rectangle {
    struct point tl; // top left. 사각형의 좌 상단
    struct point br; // bottom right. 사각형의 우 하단
};

//main.c
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct rectangle *p;
    int x_diff, y_diff;

    p = (struct rectangle *)malloc(sizeof(struct rectangle));
    if (p == NULL)
    {
        printf("No more memmory");
        exit(1);
    }

    printf("Enter x, y, of top left\n");
    scanf("%d %d", &(p->tl).x, &(p->tl).y);
    printf("Enter x, y of bottom right\n");
    scanf("%d %d", &(p->br).x, &(p->br).y);

    x_diff = abs((p->br).x - (p->tl).x); // x값 차이
    y_diff = abs((p->br).y - (p->tl).y);
    printf("The area of rectangle is, %d\n", x_diff * y_diff);

    return 0;
}

 */

/*
//ex 13-5
#include <stdio.h>
struct point {
  int x;
  int y;
};

struct point increment(struct point s){
  s.x += 1;
  s.y += 1;
  return s;
}

int main(){
  struct point a = {1,1}, b, c;

  b = a;
  printf("b is (%d, %d)\n", b.x,b.y); // (1,1);

  c = increment(a);
  printf("c is (%d, %d)\n", c.x,c.y); // (2,2)

  if(a.x == b.x && a.y == b.y)
    printf("a and b have same value\n");
  if(&a == &b)
    printf("a and b are same points\n");

  return 0;
}

 */

/*
//ex 13-6
#include <stdio.h>

struct person{
  char name[10];
  int age;
};

int over_twenty(const struct person *p){
  if(p -> age > 20)
    return 1;
  else
    return 0;
}

int main(){
  struct person s1, s2 = {"Jay", 24};

  s1 = s2;
  printf("s1's name is %s.\n", s1.name);

  if(over_twenty(&s1))
    printf("%s is over twenty.\n", s1.name);

  return 0;
}
 */

/*
//ex 13-7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  int entry_year;    //입사연도
  char residence[6];    //거주지
  char* name;     //사원 이름
};

int main() {
  struct employee a = {2019, "Seoul", NULL};
  struct employee b;

  a.name = (char*)malloc(sizeof(char) * 5);
  strcpy(a.name, "Lee");

  b = a;
  strcpy(b.name, "Park");

  printf("%d %s %s\n", a.entry_year, a.residence, a.name);
  printf("%d %s %s\n", b.entry_year, b.residence, b.name);

  return 0;
}
 */

/*
//ex 13-8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  int entry_year;
  char residence[6];
  char* name;
};

void show_name(struct employee her) {
  printf("%s\n", her.name);
  strcpy(her.name, "홍두루미");
}

int main() {
  struct employee a = {2019, "Seoul", NULL};
  a.name = (char*)malloc(9 * sizeof(char));
  strcpy(a.name, "박하영");

  show_name(a);
  printf("%s\n", a.name);

  return 0;
}
 */

/*
//ex 13-9
#include <stdio.h>

int main() {
  int i;
  int entry[3] = {201504, 202011, 202502}; //입사연월
  char name[3][20] = {"Kim", "Lee", "Park"}; //이름
  char phone[3][15] = {"1234242", "124215215", "1242152"}; //전번

  for(i = 0; i < 3; i++)
    printf("%d %s %s \n", entry[i], name[i], phone[i]);

  return 0;
}
 */

/*
//ex 13-10
#include <stdio.h>
struct employee{
  int entry;
  char name[20];
  char phone[15];
};

int main(){
  int i;
  struct employee arr[3] =
            { {201504, "Kim", "1232142"},
            {202011, "Lee", "123123122"},
            {202502, "Park", "123124214"}};

  for(i=0;i<3;i++)
    printf("%d %s %s\n", arr[i].entry, arr[i].name, arr[i].phone);

  return 0;
}

 */

/*
//ex 13-11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

struct word{
  char name[20]; //단어 명
  char* meaning;
};

int main(){
  struct word *arr[MAX];
  char temp[200];
  int i = 0, j;

  while(1){
    printf("Enter word\n");
    gets(temp);
    if(strcmp(temp, "quit") == 0)
      break;
    arr[i] = (struct word*)malloc(sizeof(struct word));
    if(arr[i] == NULL)
      exit(1);
    strcpy(arr[i] -> name, temp);
    printf("Enter meaning\n");
    gets(temp);
    arr[i] -> meaning = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
    if(arr[i] -> meaning == NULL)
      exit(1);
    strcpy(arr[i] -> meaning, temp);
    i++;
    printf("\n");
  }

  printf("\nThe dictionary hs\n");
  for(j = 0; j < i; j++){
    puts(arr[j] -> name);
    puts(arr[j] -> meaning);
  }

  for(j = 0; j < i; j++){
    free(arr[j] -> name);
    arr[j] -> meaning = NULL;
  }

  for(j = 0; j<i; j++){
    free(arr[j]);
    arr[j] = NULL;
  }

  return 0;
}
 */

/*
//ex 13- 13
#include <stdio.h>
void test(){
  #define TRUE 1

  typedef int* ptrType;
  int num = 10;
  ptrType p = &num;
  printf("%d\n", *p);
}

int main(){
  //ptrType p;  -> 컴파일 오류
  test();
  printf("%d\n", TRUE);
  return 0;
}
 */
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  char* name;
  int resident_no;
};

int main() {
  struct employee seller, *p;

  p = &seller;
  p -> name = "John";
  puts(p->name);

  p -> name = (char*)malloc(sizeof(char)*40);
  //힙 영역에 40바이트 확보

  if(p -> name == NULL){
    printf("No mem\n");
    exit(1);
  }

  strcpy(p -> name, "John Lee"); // p -> name이 가리키는 곳으로 문자열이 복사
  puts(p -> name);
  free(p -> name);
  p-> name = NULL;

  return 0;
}*/

/*

#include <stdio.h>
#include <stdlib.h>
struct employee{
  int entry;
  char name[20];
  char phone[15];
};

int main(){
  struct employee arr[3] =
      {{2011,"John", "12232-2142"}
      ,{2015, "Kim", "12421-14215"}
      ,{2019, "Park", "1223-224252"}};

  for(int i=0;i<3;i++){
    printf("%d, %s, %s\n", arr[i].entry, arr[i].name, arr[i].phone);
  }

  return 0;
}
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
typedef struct{
  int id;
  char name[20];
}studentType;

int main(){
  int i, count = 0;
  studentType student, student2;

  FILE *dest = fopen("student.bin", "wb");

  student.id = 2023;
  strcpy(student.name, "James");

  count = fwrite(&student, sizeof(studentType), 1, dest);

  fclose(dest);

  FILE *src = fopen("student.bin", "rb");

  fread(&student2, sizeof(studentType), 1, src);

  printf("%d %s \n", student2.id, student2.name);
  fclose(src);

  return 0;
}
 */
/*
int main() {
  int arr[4];

  printf("&arr[0] = %p\n", &arr[0]);
  printf("&arr[0]+1 = %p\n", &arr[0]+1);
  printf("arr[1] = %p\n", &arr[1]);

  printf("arr = %p\n", arr);
  printf("arr+1 = %p\n", arr+1);

  printf("&arr = %p\n", &arr);
  printf("&arr+1 = %p\n", &arr+1);

  return 0;


}

 */


int main() {
  char dest[30], src[10];

  gets(dest);
  gets(src);

  strcat(dest, src);

  printf("%s\n", dest);

  return 0;

}