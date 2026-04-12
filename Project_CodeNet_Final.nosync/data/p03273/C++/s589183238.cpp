#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
 
#define sPRINT(str) printf(#str "\n")
#define yOUT sPRINT(Yes)
#define nOUT sPRINT(No)
#define YOUT sPRINT(YES)
#define NOUT sPRINT(NO)
 
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
 
using namespace std;

int main(void)
{   
    int h,w;
    cin >> h >> w;
    vector<string> a(h);

    vector<bool> row(h, false);
    vector<bool> col(w, false);

    REP(i, h){
        cin >> a[i];
    }

    REP(i, h){
        REP(j, w){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    REP(i,h){
        if(row[i]){
            REP(j, w){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

}