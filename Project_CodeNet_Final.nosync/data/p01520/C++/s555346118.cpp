#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int N,T,E;
    cin>>N>>T>>E;
    int ans=-1;
    for(int i=0;i<N;i++){
        int b;
        cin>>b;
        int a=T%b;
        if(a==0||a+E>=b||a-E<=0)ans=i+1;
    }
    cout<<ans<<endl;
    return 0;
}