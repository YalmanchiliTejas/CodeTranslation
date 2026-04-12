#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
 
using namespace std;
 
 
#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

char ch[10][10];
int h ,w ;
int main(){
        scanf("%d%d",&h, &w);
        for(int i=0;i<h;i++){
                scanf("%s",ch[i]);
        }
        bool ans = true;
        int last_idx= 0;
        for(int i=0;i<h;i++){
                int maxidx=-1;
                for(int j=0;j<w;j++){
                        if(ch[i][j]=='#'){
                                //cout<< i <<" "<<j <<" "<<last_idx<<endl;
                                if(j<last_idx) ans = false;
                                if(maxidx>=0 and j-maxidx!=1) ans =false;
                                maxidx=max(maxidx,j);
                        }
                }
                last_idx=maxidx;
        }
        if(ans){
                printf("Possible\n");
        }else{
                printf("Impossible\n");
        }
}