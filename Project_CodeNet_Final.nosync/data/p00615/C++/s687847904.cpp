#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b,m[1000010],max;
  while(1){
    cin >> a>> b;
    if(a==0&&b==0)break;
    for(int i=0;i<a+b;i++)cin >> m[i];
    m[a+b]=0;
    sort(m,m+a+b+1);
    max=0;
    for(int i=1;i<a+b+1;i++){
      if(m[i]-m[i-1]>max)max=m[i]-m[i-1];
    }
    cout << max<< endl;

  }
  return 0;
}