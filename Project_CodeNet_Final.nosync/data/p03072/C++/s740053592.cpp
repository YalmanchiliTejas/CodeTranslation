#include <iostream>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
 
using namespace std;
 
int main(void){
  	int N,H[100],now,result=0;
	cin>>N;
  	rep(i,N)cin>>H[i];
  	now=H[0];
	rep(i,N){
    	if(now <= H[i]){
          now=H[i];
          result++;
        }
    }
 	cout<<result<<endl;
    return 0;
}