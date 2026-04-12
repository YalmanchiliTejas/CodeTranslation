#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N;
    cin >> N;
    if(N==0) return 0;
    vector<int> datas;
    datas.resize(N);
    for(int i=0; i<N; i++) {
        cin >> datas[i];
    }
    sort(datas.begin(), datas.end());
    int sum = 0;
    int counter = 0;
    for(auto itr=datas.begin()+1; itr!=datas.end()-1; itr++) {
        sum += *itr; counter++;
    }
    cout << sum/counter << endl;
    return 1;
}

int main() {
    while(solve()) {}
}

