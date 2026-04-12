#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<sstream>
#include<stack>
#include<string>
#include<unordered_set>
#include<vector>

#define ll long long
#define P pair<int,int>
#define FOR(i,N) for(int i=0;i<(int)N;i++)
#define FORIN(i,a,b) for(int i=a;i<(int)b;i++)
#define ALL(x) (x).begin(),(x).end()
#define LAST(x) (x)[(x).size()-1]
#define GI(name) int (name);scanf("%d",&(name))
#define GI2(name1,name2) int (name1),(name2);scanf("%d %d",&(name1),&(name2))
#define GI3(name1,name2,name3) int (name1),(name2),(name3);scanf("%d %d %d",&(name1),&(name2),&(name3))
#define GVI(name,size) vector<int> (name)(size);FOR(i,(size))scanf("%d",&(name)[i])
#define MOD 1000000007

using namespace std;

string to_hex(int x){
    stringstream ss;
    ss<<hex<<x;
    return ss.str();
}

inline int get_int(){
    int ret;
    scanf("%d",&ret);
    return ret;
}

inline vector<int> get_ints(int n){
    vector<int> ret(n);
    FOR(i,n){
        scanf("%d",&ret[i]);
    }
    return ret;
}

inline string get_str(){
    string ret;
    cin>>ret;
    return ret;
}

bool is_prime(int n){
    int s=sqrt(n)+1;
    for(int i=2;i<=s;++i){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

vector<P> prime_division(int n){
    vector<P> ret;
    int s=sqrt(n)+1;
    int c=0;
    for(int i=2;i<=n;++i){
        if(n%i==0){
            c=0;
            do{
                ++c;
                n/=i;
            }while(n%i==0);
            ret.push_back(P(i,c));
        }
    }
    return ret;
}

struct UnionFind{
    vector<int> data;
    UnionFind(int size){
        data=vector<int>(size,-1);
    }
    bool union_set(int x,int y){
        x=root(x);
        y=root(y);
        if(x!=y){
            if(data[y]<data[x])swap(x,y);
            data[x]+=data[y];
            data[y]=x;
        }
        return x!=y;
    }
    bool find(int x,int y){
        return root(x)==root(y);
    }
    int root(int x){
        return data[x]<0?x:data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

string to_string(string s){
    return s;
}

template<class T>
string to_string(vector<T> v){
    string ret="{";
    FOR(i,v.size()-1){
        ret+=to_string(v[i])+",";
    }
    if(v.size()>0){
        ret+=to_string(LAST(v));
    }
    ret+="}";
    return ret;
}

void debug_print(){
    cerr<<endl;
}

template<class Head,class... Tail>
void debug_print(Head head,Tail... tail){
    cerr<<to_string(head)<<" ";
    debug_print(tail...);
}

template<class... T>
void debug(T... args){
    cerr<<"["<<__LINE__<<"]: ";
    debug_print(args...);
}

void print(){
    cout<<endl;
}

template<class Head,class... Tail>
void print(Head head,Tail... tail){
    cout<<to_string(head);
    print(tail...);
}

int main(){
    GI(N);
    string S=get_str();
    GI(K);
    char c=S[K-1];
    FOR(i,N){
        if(S[i]!=c)S[i]='*';
    }
    print(S);
    return 0;
}