#include <iostream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int a[100001]={0},b[100001]={0};
    int sum=0;
    FOR(i,0,n){
        a[i]=(s[i]=='o'?0:1);
        sum=(sum+a[i])%2;
    }
    if(n%3==0){
        b[0]=0; b[1]=0;
    }else{
        int t=(n%3==1?2:1);
        FOR(i,0,2){
            int k=0,j=i-t;
            while(j>=0){
                k=(k+a[j])%2;
                j-=3;
            }
            j=i+t;
            while(j<n){
                k=(k+a[j])%2;
                j+=3;
            }
            b[i]=(sum+k)%2;
        }
    }
    b[2]=(a[1]+b[0]+b[1])%2;
    FOR(i,3,n){
        b[i]=(b[i-3]+a[i-1]+a[i-2])%2;
    }
    if((b[n-2]+b[n-1]+b[0]+a[n-1])%2==0&&(b[n-1]+b[0]+b[1]+a[0])%2==0){
        FOR(i,0,n){
            cout<<(b[i]?"W":"S");
        }   
    }else{
        cout<<-1<<endl;
    }
    cout<<endl;
}
