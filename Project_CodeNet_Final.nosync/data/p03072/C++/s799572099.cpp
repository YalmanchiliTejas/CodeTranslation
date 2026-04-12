#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    int high=0;
    int count=0;
    for(int i=0;i<N;i++){
        cin >> H.at(i);
        high=max(high,H.at(i));
        if(H.at(i)>=high)count++;
    }
    cout << count << endl;
}
