#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int>a(n);
for(int i= 0; i< n;i++){
    cin>>a[i];
}
int count=1;
for(int  i =1 ; i <n; i++){
        int p=1;
    for(int  j =0 ; j <i; j++){
        if(a[i] < a[j]){
            p=0;
        }
    }
if(p==1)
    count++;
}

cout<<count<<endl;
}
