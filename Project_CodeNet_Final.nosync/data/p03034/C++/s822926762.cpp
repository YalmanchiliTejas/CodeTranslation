#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,s[maxn];
bool vis[maxn];
long long ans;
/**
    A+k*(A-B)=(N-1)
    Let c=(A-B)
    then we can iterate over all
    k*(A-B)<n-1
    every visit location is
    A,A-B,A+(A-B),2*(A-B),3*,......,k*(A-B),A+k*(A-B)
    A,C,A+C,2*C,A+2*C,....,A+k*(C)
    Then let's get rid of A
    remember that A is just equal to (N-1)-(k*C)
    The total number of A is k+1
    C,2*C,...,(K-1)*C
    N-1,(N-1)-C,.....(N-1)-C*(K-1)
*/

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    for(int c=1;c<n;c++){
            long long sum=0;
            vector<int> ch;
       /// cerr<<c<<'\n';
        for(int k=1;1LL*c*(k-1)<n;k++){
            int id=(k-1)*c;
            if(vis[id]){
                break;
            }
            else{
             vis[id]=true;
             ch.push_back(id);
             sum+=s[id];
            }
          ///  cerr<<id<<' ';
            id=n-1-c*(k-1);
            if(id<=c){
                break;
            }
        ///    cerr<<id<<' ';
            if(vis[id]){
                break;
            }
            else{
                vis[id]=true;
                sum+=s[id];
                ch.push_back(id);
            }
            ans=max(ans,sum);
        }
        for(int i:ch){
            vis[i]=false;
        }
     ///   cerr<<'\n';
      ///  cerr<<ans<<'\n';
    }
    printf("%lld\n",ans);
}
/*
    Good Luck
        -Lysithea
        a-b=6 k-1=2
        a+(k-1)*(a-b)==n-1
        1
14
0 -59616710 783365911 111189909 -256968442 -989501104 261125694 972992891 -605457409 47321305 -21631829 -235268167 922418061 0
*/
