#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int N;
    cin>>N;
    int h[20];
    int ans=1;
    for(int i=0;i<N;i++){
        int k;
        cin>>k;
        h[i]=k;
    }
    int m=h[0];
    for(int i=1;i<N;i++){
        m=max(m,h[i-1]);
        if(m<=h[i])ans++;
    }
    cout<<ans<<endl;
}