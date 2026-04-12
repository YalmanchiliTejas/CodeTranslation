#include <iostream>

using namespace std;

int main(){
        int N, T, E;
        cin >> N >> T >> E;
        int answer = -1;
        for(int i = 0; i < N; ++i){
                int x;
                cin >> x;
                int m = T % x;
                if(m <= E || x - E <= m){ answer = i + 1; }
        }
        cout << answer << endl;
        return 0;
}