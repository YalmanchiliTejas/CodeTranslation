#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
//#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef long long ll;
typedef pair<ll,ll> PP;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

int N;
vector<bool> S,T;
bool illegal = false;
vector<vector<int>> solve01(vector<bool> U,vector<bool> V);
bool legal_checker(vector<bool> U,vector<bool> V,vector<vector<int>> R);

signed main(void){
    vector<unsigned long long> U,V;
    vector<bool> u,v;
    
    cin >> N;
    bool a;
    unsigned long long b;
    
    REP(i,N){cin >> a;S.push_back(a);}
    REP(i,N){cin >> a;T.push_back(a);}
    REP(i,N){cin >> b;U.push_back(b);}
    REP(i,N){cin >> b;V.push_back(b);}
    
    vector<vector<unsigned long long>> Ans;
    Ans.resize(N);
    REP(i,N){
        Ans[i].clear();
        REP(j,N){
            Ans[i].push_back(0);
        }
    }
    
    unsigned long long k=1;
    REP(_,64){
        u.clear();v.clear();
        REP(i,N){
            u.push_back((U[i]>>_)%2);
        }
        REP(i,N){
            v.push_back((V[i]>>_)%2);
        }
        
        vector<vector<int>> ans = solve01(u,v);
        bool check = legal_checker(u,v,ans);
        if(!check)illegal=true;
        if(illegal)break;
        
        REP(i,N){
            REP(j,N){
                Ans[i][j]+=k*ans[i][j];
            }
        }
        k*=2;
    }
    
    
    if(illegal){
        cout << -1 << endl;
    }else{
        REP(j,N){
            REP(i,N){
                cout << Ans[j][i];
                if(i==N-1){cout << endl;}else{cout << " ";}
            }
        }
    }
    
    return 0;
}




vector<vector<int>> solve01(vector<bool> U,vector<bool> V){
    /*
    -1で初期化しておく
    andが1ということはその行(列)はすべて1なので1で埋めておく
    orが0ということはその行(列)はすべて0なので0で埋めておく
    この時点で矛盾すれば違法として抜ける
    埋まらなかったもの(-1のまま)が各行各列にどれだけあるかによって挙動を変える
    
    r>=2かつc>=2なら市松模様でOK
    r=1なら、その列だけ見る
    　ほかの列が0埋めか1埋めされていることになる
    c=1なら、その行だけ見る
    r=0,c=0なら何もしない
    
    */
    
    
    
    //-1で初期化
    vector<vector<int>> R;
    R.resize(N);
    REP(i,N){
        R[i].clear();
        REP(j,N){
            R[i].push_back(-1);
        }
    }
    
    
    //まず確定させる
    REP(i,N){
        if(S[i]==0 && U[i]==1){
            REP(j,N){
                R[i][j] = 1;
            }
        }
        if(S[i]==1 && U[i]==0){
            REP(j,N){
                R[i][j] = 0;
            }
        }
    }
    REP(j,N){
        if(T[j]==0 && V[j]==1){
            REP(i,N){
                if(R[i][j]==0){
                    illegal = true;
                }
                R[i][j] = 1;
            }
        }
        if(T[j]==1 && V[j]==0){
            REP(i,N){
                if(R[i][j]==1){
                    illegal = true;
                }
                R[i][j] = 0;
            }
        }
    }
    
    if(illegal)return R;
    
    //確定していない行・列を数える
    
    int r=0,c=0;
    vector<int> ri,cj;
    
    REP(i,N){
        if((S[i]==0 && U[i]==0)||(S[i]==1 && U[i]==1)){
            r++;
            ri.push_back(i);
        }
    }
    
    REP(j,N){
        if((T[j]==0 && V[j]==0)||(T[j]==1 && V[j]==1)){
            c++;
            cj.push_back(j);
        }
    }
    
    
    #if debug
    cout << "S: ";REP(i,N){cout << (S[i]?"or":"ad") << " ";}cout << endl;
    cout << "T: ";REP(i,N){cout << (T[i]?"or":"ad") << " ";}cout << endl;
    cout << "U: ";REP(i,N){cout << U[i] << " ";}cout << endl;
    cout << "V: ";REP(i,N){cout << V[i] << " ";}cout << endl;
    cout << "R: " << endl;
    REP(j,N){
        REP(i,N){
            cout << R[i][j] << " ";
        }cout << endl;
    }
    cout << "! " << r << " " << c << endl;
    #endif
    
    //rとcの値で場合分け
    //r==0(c==0)の場合　素通り
    //r==1の場合　その列だけ処理を行う
    //c==1の場合　その行だけ処理を行う
    //それ以外の場合 市松模様
    
    if(r==0 || c==0){
        
    }else if(r==1){
        int p = ri[0];
        bool questz=false,questo=false;
        REP(i,N){
            if(R[i][0]==0){
                questz=true;
            }
            if(R[i][0]==1){
                questo=true;
            }
        }
        
        if(questz && questo){
            REP(j,N){
                R[p][j]=U[p];
            }
        }
        
        for(int &j : cj){
            R[p][j]=V[j];
        }
        
        bool r = R[p][0];
        REP(j,N){
            if(S[p]==0){
                r = (r and R[p][j]);
            }else{
                r = (r or R[p][j]);
            }
        }
        if(r != U[p]){
            int j = cj[0];
            R[p][j]=V[j];
            if((V[j]==0 && !questo)||(V[j]==1 && !questz)){
                R[p][j]^=1;
            }
        }
        
        
    }else if(c==1){
        int q = cj[0];
        bool questz=false,questo=false;
        REP(j,N){
            if(R[0][j]==0){
                questz=true;
            }
            if(R[0][j]==1){
                questo=true;
            }
        }
        
        if(questz && questo){
            REP(i,N){
                R[i][q]=V[q];
            }
        }
        
        for(int &i : ri){
            R[i][q]=U[i];
        }
        
        bool r = R[0][q];
        REP(i,N){
            if(T[q]==0){
                r = (r and R[i][q]);
            }else{
                r = (r or R[i][q]);
            }
        }
        if(r != V[q]){
            int i = ri[0];
            R[i][q]=U[i];
            if((U[i]==0 && !questo)||(U[i]==1 && !questz)){
                R[i][q]^=1;
            }
        }
        
    }else{
        
        int i_=0,j_=0;
        for(int &i : ri){
            for(int &j : cj){
                R[i][j]=(i_+j_)%2;
                j_++;
            }
            j_=0;
            i_++;
        }
        
    }
    
    #if debug
    cout << "R: " << endl;
    REP(j,N){
        REP(i,N){
            cout << (int)R[i][j];
            if(i==N-1){cout << endl;}else{cout << " ";}
        }
    }cout << endl;
    #endif
    
    return R;
}

bool legal_checker(vector<bool> U,vector<bool> V,vector<vector<int>> R){
    bool check = true;
    REP(i,N){
        bool r = R[i][0];
        REP(j,N){
            if(S[i]==0){
                r = (r and R[i][j]);
            }else{
                r = (r or R[i][j]);
            }
        }
        if(r != U[i])check = false;
    }
    
    
    REP(j,N){
        bool r = R[0][j];
        REP(i,N){
            if(T[j]==0){
                r = (r and R[i][j]);
            }else{
                r = (r or R[i][j]);
            }
        }
        if(r != V[j])check = false;
    }
    return check;
}

