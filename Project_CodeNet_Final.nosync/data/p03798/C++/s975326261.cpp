#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string s;
ll N;
vector<char> v[4];

char inv(char c){
    if(c == 'S') return 'W';
    return 'S';
}

int main(){
    cin >> N;
    cin >> s;
    v[0].push_back('S');
    v[0].push_back('S');
    v[1].push_back('S');
    v[1].push_back('W');
    v[2].push_back('W');
    v[2].push_back('S');
    v[3].push_back('W');
    v[3].push_back('W');
    for(int i=0;i<4;i++){
        for(int j=2;j<N;j++){
            if(s[j-1] == 'o'){
                if(v[i][j-1] == 'S'){
                    v[i].push_back(v[i][j-2]);
                }else{
                    v[i].push_back(inv(v[i][j-2]));
                }
            }else{
                if(v[i][j-1] == 'S'){
                    v[i].push_back(inv(v[i][j-2]));
                }else{
                    v[i].push_back(v[i][j-2]);
                }
            }
        }
        if(s[0] == 'o'){
            if(v[i][0] == 'S'){
                if(v[i][1] != v[i][N-1]) continue;
            }else{
                if(v[i][1] == v[i][N-1]) continue;
            }
        }else{
            if(v[i][0] == 'S'){
                if(v[i][1] == v[i][N-1]) continue;
            }else{
                if(v[i][1] != v[i][N-1]) continue;
            }
        }
        if(s[N-1] == 'o'){
            if(v[i][N-1] == 'S'){
                if(v[i][0] != v[i][N-2]) continue;
            }else{
                if(v[i][0] == v[i][N-2]) continue;
            }
        }else{
            if(v[i][N-1] == 'S'){
                if(v[i][0] == v[i][N-2]) continue;
            }else{
                if(v[i][0] != v[i][N-2]) continue;
            }
        }
        for(int j=0;j<N;j++){
            cout << v[i][j];
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}