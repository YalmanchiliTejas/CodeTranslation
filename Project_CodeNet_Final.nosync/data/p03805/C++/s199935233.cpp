#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int N, M;
int a[30], b[30];

int jud(vector<int> v){
    int cou = 0;

    if(v[0] == 1){
        for(int i = 0; i < N - 1; i++){
            vector<int>::value_type t = v[i];
            vector<int>::value_type s = v[i + 1];
            if(t > s){
                for(int j = 0; j < M; j++){
                    if(t == b[j] && s == a[j]){
                            cou++;              
                    }
                }
            }else{
                for(int j = 0; j < M; j++){
                    if(t == a[j] && s == b[j]){
                        cou++;                    
                    }
                }
            }
        }
        if(cou == N - 1){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

    return 0;
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        v[i] = i + 1;
    }

    int ans =0;
 
    do {
        ans += jud(v);
        /*for(int i = 0; i < N; i++){
            cout << v[i] << " ";
        }
        cout << endl;
        cout << ans << endl;*/
    } while( next_permutation(v.begin(), v.end()) );     

    cout << ans << endl;
}