#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0))
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0))
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a))
#define Reverse(a) reverse(All(a))
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl;
#define Print(a) cout << (a);
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<int>& a,int n);
class Modulo{
public:
    int val;
    static const int mod = 1e9+7;
    vector<int> factable = {1};
    vector<int> invtable = {1};
    int pro(int x,int y){return ((x%mod)*(y%mod))%mod;}
    int sum(int x,int y){return ((x%mod)+(y%mod))%mod;}
    int dif(int x,int y){int d =((x%mod)-(y%mod))%mod;if(d>=0){return d;}else{return d+mod;}}
    int quo(int x, int y){return pro(x,pow(y,mod-2));}
    int pow(int x,int y){
        if(y<=0){return 1;}
        if(y%2==0){int d = pow(x,y/2);return ((d%mod)*(d%mod))%mod;}
        else{return (x*pow(x,y-1))%mod;}
    }
    void operator=(int n){this->val = n%mod;}
    int operator+(int n){return sum(this->val,n);}
    int operator-(int n){return dif(this->val,n);}
    int operator*(int n){return pro(this->val,n);}
    int operator/(int n){return quo(this->val,n);}
    void operator+=(int n){this->val = sum(this->val,n);}
    void operator-=(int n){this->val = dif(this->val,n);}
    void operator*=(int n){this->val = pro(this->val,n);}
    void operator/=(int n){this->val = quo(this->val,n);}
    int fac(int x){
        //x! mod mod
        if(factable.size()<=x){
            int s = factable.size();
            FOR(i,s,x+1){
                factable.push_back(pro(i,factable.back()));
                invtable.push_back(quo(1,factable.back()));
            }
        }
        if(x<0) return 1;
        else return factable[x];
    }
    int facinv(int x){
        if(invtable.size()<=x){
            int s = invtable.size();
            FOR(i,s,x+1){
                factable.push_back(pro(i,factable.back()));
                invtable.push_back(quo(1,factable.back()));
            }
        }
        if(x<0) return 1;
        else return invtable[x];
    }
    int com(int x,int y){
        //xCy mod mod = x!/((x-y)!*y!) mod mod
        if(x-y<y)return com(x,x-y);
        return pro(fac(x),pro(facinv(x-y),facinv(y)));
    }
};




int n,m;

signed main(){
    int l;
    string s,t;
    cin >> l >> s >> t;
    int x = s.size();
    int y = t.size();
    int a = l/x;
    int tmp=l;
    string ans_a,ans_b;
    for(int i = a;i>=0;i--){
        tmp -= x*i;
        if(tmp%y==0){
            REP(j,i){
                ans_a += s;
            }
            REP(j,tmp/y){
                ans_a += t;
            }
            break;
        }
        tmp = l;
    }
    swap(s,t);
    swap(x,y);
    a = l/x;
    tmp = l;
    for(int i = a;i>=0;i--){
        tmp -= x*i;
        if(tmp%y==0){
            REP(j,i){
                ans_b += s;
            }
            REP(j,tmp/y){
                ans_b += t;
            }
            break;
        }
        tmp = l;
    }
    string ans;
    if(ans_a>ans_b){
        ans = ans_b;
    }
    else{
        ans = ans_a;
    }
    print(ans);

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<int>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}
