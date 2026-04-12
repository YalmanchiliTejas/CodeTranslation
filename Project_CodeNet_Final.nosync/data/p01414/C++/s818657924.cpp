#include<bits/stdc++.h>
using namespace std;
char Color[3] = {'R', 'G', 'B'};

int main(){

    int n; cin >> n;
    vector<int> h(n);
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> h[i] >> w[i];
    string C;
    for(int i = 0; i < 4; i++){
        string tmp; cin >> tmp;
        C = C + tmp;
    }

    queue<pair<int, int> > que;                  //cost bit(一致していたら1そうでなければ0)
    
    vector<bool> used((1 << 16), false);
    used[0] = true;
    que.push({0, 0});

    while(!que.empty()){

        int bit = que.front().second;
        int cost = que.front().first;
        //cout << cost << " " << str << endl;
        que.pop();

        if(bit == (1 << 16) - 1){
            cout << cost << endl;
            break;
        }

        for(int ii = 0; ii < n; ii++){

            for(char color : Color){

                //cout << i << " " << color << endl;
                for(int si = -3; si <= 3; si++){
                    for(int sj = -3; sj <= 3; sj++){
                        int gi = si + h[ii] - 1;
                        int gj = sj + w[ii] - 1;

                        int next;
                        next = bit;
                        //cout << i << " " << si << " " << gi << " " << sj << " " << gj << " " << endl;
                        for(int i = max(si, 0); i <= min(gi, 3); i++){
                            for(int j = max(sj, 0); j <= min(gj, 3); j++){            
                                int idx = i * 4 + j;
                                if(C[idx] == color) next = next | (1 << idx);
                                else next = next & ~(1 << idx);
                            }
                        }

                        if(!used[next]){
                            //cout << "ok" << endl;
                            used[next] = true;
                            que.push({cost + 1, next});
                        }

                    }
                }
            }
        }
    }

    return 0;
}
