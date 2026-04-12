#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

int main()
{
    int N;
    string s;
    cin >> N >> s;

    vector<string> v{"SS","SW","WS","WW"};
    for(int i = 1; i < N; ++i){
        for(int j = 0; j < 4; ++j){
            if(s[i] == 'o'){
                if(v[j][i] == 'S') v[j] += v[j][i-1];
                else{
                    if(v[j][i-1] == 'S') v[j] += 'W';
                    else v[j] += 'S';
                }
            }else{
                if(v[j][i] != 'S') v[j] += v[j][i-1];
                else{
                    if(v[j][i-1] == 'S') v[j] += 'W';
                    else v[j] += 'S';
                }
            }
        }
    }

    for(int i = 0; i < 4; ++i){
        if(v[i].front() == v[i].back()){
            v[i].pop_back();
            if(v[i].front() == 'S'){
                if(s[0] == 'o'){
                    if(v[i][1] == v[i].back()){
                        cout << v[i] << endl;
                        return 0;
                    }
                }else{
                    if(v[i][1] != v[i].back()){
                        cout << v[i] << endl;
                        return 0;
                    }
                }
            }else{
                if(s[0] == 'o'){
                    if(v[i][1] != v[i].back()){
                        cout << v[i] << endl;
                        return 0;
                    }
                }else{
                    if(v[i][1] == v[i].back()){
                        cout << v[i] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}