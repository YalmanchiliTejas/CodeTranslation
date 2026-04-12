#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N, M, a, b, count=0; 
    bool e[9][9]={{0}};
    vector<int> v;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    for(int i=1;i<=N;i++) v.push_back(i);
    do {
        if(v[0]==1){
            for(int i=0; i<v.size()-1; i++) {
                if(e[v[i]][v[i+1]]){
                    if(i==v.size()-2) count++;
                }
                else break;
            }
        }
        //cout << count << endl;
    } while (next_permutation(v.begin(), v.end()));
    cout << count << endl;
    return 0;
}