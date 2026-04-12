#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;
typedef long long ll;


int main(){
        ll N;
        cin >> N;
        string S;
        cin >> S;
        vector<vector<int>> ans(4, vector<int>(N));

        ans[0][0] = 0;
        ans[0][1] = 0;
        ans[1][0] = 0;
        ans[1][1] = 1;
        ans[2][0] = 1;
        ans[2][1] = 0;
        ans[3][0] = 1;
        ans[3][1] = 1;
        for(ll i=2; i<N; i++){
                for(int k=0; k<4; k++)
                        if(S[i-1] == 'o'){
                                if(ans[k][i-1] == 0) ans[k][i] = ans[k][i-2];
                                else ans[k][i] = (ans[k][i-2]+1)%2;
                        }
                        else{
                                if(ans[k][i-1] == 1) ans[k][i] = ans[k][i-2];
                                else ans[k][i] = (ans[k][i-2]+1)%2;
                        }
        }
        vector<bool> flag1(4), flag2(4);
        for(int i=0; i<4; i++){
                if(S[0] == 'o'){
                        if(ans[i][0] == 0 && ans[i][N-1] == ans[i][1]){ flag2[i]=true;}
                        else if(ans[i][0] == 1 && ans[i][N-1] != ans[i][1]){ flag2[i]=true;}
                }
                else{
                        if(ans[i][0] == 1 && ans[i][N-1] == ans[i][1]){ flag2[i]=true;}
                        else if(ans[i][0] == 0 && ans[i][N-1] != ans[i][1]){ flag2[i]=true;}

                }
        }
        for(int i=0; i<4; i++){
                if(S[N-1] == 'o'){
                        if(ans[i][N-1] == 0 && ans[i][N-2] == ans[i][0]){ flag1[i] = true;}
                        else if(ans[i][N-1] == 1 && ans[i][N-2] != ans[i][0]){ flag1[i] = true;}
                }
                else{
                        if(ans[i][N-1] == 1 && ans[i][N-2] == ans[i][0]){ flag1[i] = true;}
                        else if(ans[i][N-1] == 0 && ans[i][N-2] != ans[i][0]){ flag1[i] = true;}
                }
        }


        for(int k=0; k<4; k++){
                if(flag1[k] && flag2[k]){
                for(ll i=0; i<N; i++){
                        if(ans[k][i]==0) cout << "S";
                        else cout << "W";
                }break;
                }
        if(k==3) cout << -1;
        }
}
