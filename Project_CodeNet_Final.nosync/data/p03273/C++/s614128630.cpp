#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main () {
    string S[105];
    int x[105]={0, }, y[105]={0, };
    int N, M;
    cin >> N >> M;
    for (int i=0;i<N;i++)
        cin >> S[i];
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (S[i][j]=='#'){
                x[i]++;
                y[j]++;
            }
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (x[i] && y[j])
                cout << S[i][j];
        }
        if (x[i])
        cout << "\n";
    }
    return 0;
}