#include <iostream>
#include <vector>
#include <cstring>



#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;

int main(){
    ll H,W;
    cin >> H >> W;
    string tmp;
    vector <string> S(H); 


    REP(i,H)
    {
        cin >> S[i];
    }

    ll delCnt = 0;

    bool flg = true;
    for(ll j = 0; j < S[0].size();j++)
    {
        flg = false;
        REP(i,H)
        {
            if(S[i][j] == '#')flg = true;
        }
        if(flg == false)
        {
            REP(i,H)
            {
                S[i].erase(j,1);
            }
            delCnt++;
            j--;
        }
    }

    //行削除
    REP(i,H)
    {
        flg = false;
        REP(j,W)
        {   
            if(S[i][j] == '#')flg = true;
        }

        if(flg == true)
        {
            cout << S[i] << endl;
        }
    }
}


