#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0; i<N; i++){
        cin >> H.at(i);
    }
    int m = H.at(0);
    int count =1;
    for(int i=1; i<N; i++){
        if( H.at(i) == max(m, H.at(i))){
            count++;
            m = max(m, H.at(i));
        }
    }
    cout << count << endl;


}