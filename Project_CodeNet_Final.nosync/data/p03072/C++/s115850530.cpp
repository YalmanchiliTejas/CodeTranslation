#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int max=a[0];
  int count=0;
  for(int i=0;i<n;i++){
    if(a[i]>=max){
      count++;
      max=a[i];
    }
  }
  cout<<count<<endl;
  return 0;
}
