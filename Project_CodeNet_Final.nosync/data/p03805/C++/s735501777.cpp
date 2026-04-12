#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<bool> > Connection(N+1, vector<bool>(N+1, false));
    for(int m=0; m<M; m++) {
        int a, b;
        cin >> a >> b;
        Connection[a][b]=true;
        Connection[b][a]=true;
    }
    
    vector<int> per_vec(N-1);
    for(int n=0; n<N-1; n++) {
        per_vec[n] = n+2;
    }
    
    int counter=0;
    do {
        bool flag=true;
        if(!Connection[1][per_vec[0]]) continue;
        for(int n=0; n<N-2; n++) {
            if(!Connection[per_vec[n]][per_vec[n+1]]) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            counter++;
        }
    } while(next_permutation(per_vec.begin(), per_vec.end()));
    
    cout << counter << endl;

    return 0;
    
}