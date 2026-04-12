#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  int N, l[100001];
  int index=1;
  int a;
  cin >> N;
  cin >> a;
  l[0] = a;
  for (int i=1; i<N ;i++) {
    scanf("%d", &a);

    for(int j=index/2, min=0, max=index-1;;j = (max + min)/2) {
      if (l[j] >= a) {
        min = (max + min + 1) / 2;
        if (j+1 == index) {
          l[index] = a;
          index++;
          break;
        }
      } else if (l[j] < a) {
        if (j - 1 < 0 || l[j-1] >= a){
          l[j] = a;
          break;
        }
        else {
          max = (max + min) / 2;
        }
      }
    }
  }
  cout << index << endl;
  return 0;
}