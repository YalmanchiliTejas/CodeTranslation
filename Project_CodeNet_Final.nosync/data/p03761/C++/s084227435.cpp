#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int N;
string S[55];
map<char, int> mp_nums;

void clear_mp_nums(string S){
    for(auto itr = mp_nums.begin(); itr != mp_nums.end(); ++itr) 
        if((int)S.find(itr->first) == -1) mp_nums.erase(itr->first);
}

int cnt_chars(string S, char c){
    int cnt = 0;
    for(int i = 0; i < S.size(); i++)
        if(S[i] == c) cnt++;
    return cnt;
}

void solve(){
    for(int i = 0; i < S[0].size(); i++){
        char c = S[0][i];
        mp_nums[c] = cnt_chars(S[0], c);
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < S[i].size(); j++){
            char c = S[i][j];
            if(mp_nums[c]==0) continue;
            else {
                mp_nums[c] = min(mp_nums[c],cnt_chars(S[i], c));
            }
        }
        clear_mp_nums(S[i]);
    }

    if(mp_nums.size()==0) cout << "";
    else{
        for(auto itr = mp_nums.begin(); itr != mp_nums.end(); ++itr) {
            for(int k = 0; k < mp_nums[itr->first]; k++)
                    cout << itr->first;
        }
    }
    cout << endl;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> S[i];

    solve();
}
