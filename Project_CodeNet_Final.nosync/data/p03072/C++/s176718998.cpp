#include <iostream>
using namespace std;

int main(){
  int N;  cin >> N;
  int a[20];
  for(int i = 0;i < N;i++)cin >> a[i];

  int count = 0;
  for(int i = 0;i < N;i++){
    bool flag = true;
    for(int j = 0;j < i;j++){
      if(a[i] < a[j])flag = false;
    }

    if(flag)count++;
  }

  cout << count << endl;
}