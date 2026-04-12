#include<iostream>
using namespace std;

int n,s[100];
int temp,ave,sum;

void sort(void){
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(s[i]>s[j]){
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
      }
    }
  }
}

int main(){
  while(cin >> n,n){
    for(int i=0;i<n;i++)
      cin >> s[i];  
    
    sort();
    
    sum=0;

    for(int i=0;i<n-2;i++)
      sum+=s[i+1];

    cout << sum/(n-2) << endl;
  }
  return 0;
}