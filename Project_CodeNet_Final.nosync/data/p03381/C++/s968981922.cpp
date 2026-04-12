#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a;
    vector <pair <int, int> > b;
    vector <int> otv(n, 0);
    int th;
    for (int i=0; i<n; i++){
        cin >> th;
        a.push_back(th);
        b.push_back(make_pair(th, i));
    }
    sort(b.begin(), b.end());
    for (int i=0; i<n; i++){
        if ((i+1)*2 <= n){
            otv[b[i].second] = b[(n-1) / 2 + 1].first;
        }
        else{
            otv[b[i].second] = b[((n-1)/ 2)].first;
        }
    }
    for (int i=0; i<n; i++){
        cout << otv[i] << ' ';
    }
    return 0;
}