#include <stdio.h>

int a, b, c = 0;
int x, y = 0;
int price = 0;
int min = 0;


int case1(int a, int b, int x, int y) {
  price = a * x + b * y;

  return price;
}

int case2(int c, int x, int y) {
  if(x > y) {
    price = c * 2 * x;
  }else{
    price = c * 2 * y;
  }

  return price;
}

int case3(int a, int b, int c, int x, int y) {
  if(x > y) {
    price = c * 2 * y + (x - y) * a;
  }else if(x < y) {
    price = c * 2 * x + (y - x) * b;
  }

  return price;
}

int compare(int a, int b, int c, int x, int y) {
  min = case1(a, b, x, y);
  if(min > case2(c, x, y)) {
    min = case2(c, x, y);
  }

  if(min > case3(a, b, c, x, y)) {
      min = case3(a, b, c, x, y);
  }

  return min;
}
  


int main(void) {

  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);


  printf("%d\n", compare(a, b, c, x, y));


  return 0; 

}
