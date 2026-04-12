#include<iostream>
using namespace std;

int a,b=0,temp;
int maxi=0;
int mini=100000;
long sum=0;
int result[1000];

int main(){

  while(cin >> a && a!=0){
    for(int i=0;i<a;i++){
      cin >> temp;
      sum+=temp;
      if(temp>maxi)maxi=temp;
      if(temp<mini)mini=temp;
      //cout <<maxi<<mini<<sum<< endl;
    }
    result[b]=(sum-maxi-mini)/(a-2);
    b++;
    //cout << (sum-maxi-mini)/(a-2) << endl;
    maxi=0;
    mini=100000;
    sum=0;
    //temp=0;
  }

  for(int i=0;i<b;i++){
    cout << result[i] << endl;
  }
}

