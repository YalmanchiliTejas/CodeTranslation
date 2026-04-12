#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[210];
int q[210];
vector<pair<int,int> > mr;
int N;
void wolf(int a){
    for(int i=a;i<N;i++)swap(p[i],p[i-a]);
   // printf("%d: ",a);
    for(int i=0;i<N;i++){
       // if(i)printf(" ");
     //   printf("%d",p[i]);
    }
   // printf("\n");
}
int main(){
    int a;scanf("%d",&a);
    N=a;
    for(int i=0;i<a;i++){scanf("%d",p+i);}
    for(int i=0;i<a;i++)q[i]=p[i];
    for(int i=0;i<a;i++){
        for(int j=1;j<a;j++){
            if(q[j]<q[j-1]){
                mr.push_back(make_pair(j-1,j));
                swap(q[j],q[j-1]);
            }
        }
    }
    vector<int>ret;
    int ori=0;
    for(int i=0;i<mr.size();i++){
        int L=mr[i].first;
        int rem=(L+1-ori+a)%a;
        while(rem){
            int mv=min(rem,1);
            ret.push_back(mv);
            wolf(mv);
            rem-=mv;
        }
        ret.push_back(a-1);
        wolf(a-1);
        ori=(L+1)%a;
 
    }
    int rem=(a-ori)%a;
    while(rem){
        int mv=min(rem,1);
        ret.push_back(mv);
        wolf(mv);
        rem-=mv;
    }
    assert(ret.size()<=100000);
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++){
        printf("%d\n",ret[i]);
    }
}