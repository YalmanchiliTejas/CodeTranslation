#include<bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;

#define debugv(v) printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;
#define debugm(m) printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;
#define debugaa(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}
#define ALL(v) (v).begin(),(v).end()
#define BIGINT 0x7FFFFFFF
#define E107 1000000007
void printbit(int u){if(u==0)cout<<0;else{int s=0,k=0;for(;0<u;u>>=1,k++)s=(s<<1)|(u&1);for(;0<k--;s>>=1)cout<<(s&1);}}

#define TIME chrono::system_clock::now()
#define MILLISEC(t) (chrono::duration_cast<chrono::milliseconds>(t).count())

template<typename T1,typename T2>
ostream& operator <<(ostream &o,const pair<T1,T2> p){o<<"("<<p.first<<":"<<p.second<<")";return o;}

int m,n;

int zanzo[100010];
int magic(int p){
    if (zanzo[p]&1){
        zanzo[p-1]|=2;
        zanzo[p+1]|=2;
    }
}

int main(){
    int i,j,k;
    
    cin >>n>>m;
    
    zanzo[1]=1;
    int p=1;
    int a,b;
    for (i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        magic(p);
        swap(zanzo[a],zanzo[b]);
        if (zanzo[a]&1)
            p=a;
        if (zanzo[b]&1)
            p=b;
        magic(p);
    }
    int count = 0;
    for (i=1;i<=n;i++){
        count+=!!zanzo[i];
    }
    
    //debuga(zanzo,n+1);
    cout << count << endl;
    

    return 0;
}