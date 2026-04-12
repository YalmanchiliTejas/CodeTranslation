#include<bits/stdc++.h>
using namespace std;

int N;
int d[6];
void change(int i,int j,int k,int l){
    i--;j--;k--;l--;
    int x=d[i];
    d[i]=d[j];
    d[j]=d[k];
    d[k]=d[l];
    d[l]=x;
}
void solve(){
    for(int i=0;i<6;i++)d[i]=i+1;
    int sum=1;

    while(N--){
        string str;
        cin>>str;
        switch(str[0]){
        case 'N':change(1,2,6,5);break;
        case 'E':change(1,4,6,3);break;
        case 'W':change(1,3,6,4);break;
        case 'S':change(1,5,6,2);break;
        case 'R':change(2,3,5,4);break;
        case 'L':change(2,4,5,3);break;
        }
        sum+=d[0];
    }
    cout<<sum<<endl;
}

int main(){
    while(cin>>N,N)solve();
    return 0;
}