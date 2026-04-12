#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void){
int N;
cin>>N;
char str[N+1];
cin>>str;
int K;
cin>>K;
char check=str[K-1];
for(int i=0;i<N;i++){
    if(str[i]!=check){cout<<'*';}
    else cout<<check;
}
return 0;
}
