#include<algorithm>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<map>
using namespace std;

int main(){
//srandom((unsigned long)time(NULL));

int n;
cin>>n;
int h[n];
for(int i=0;i<n;i++){
    cin>>h[i];
}
int cnt=1;

for(int i=1;i<n;i++){
    int x=0;
    for(int j=0;j<i;j++){
        if(h[j]>h[i]){
            x=1;
        }
    }
    if(x==0)cnt+=1;

}
cout<<cnt<<endl;


return 0;
}