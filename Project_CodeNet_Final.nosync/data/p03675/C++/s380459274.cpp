#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<deque>
using namespace std;
int ans[300005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    //cout<<(n-i)/2<<" "<<n-(n-i)/2<<endl;
    if(i%2==0){
    if(n%2==0)
    ans[1+(n-i)/2]=x;
    else
    ans[n-(n-i)/2]=x;
    }
    else{
    if(n%2==0)
    ans[n-(n-i)/2]=x;
    else
    ans[1+(n-i)/2]=x;     
    }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    //system("pause");
    return 0;
}
