#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int N;
cin >> N;
vector<int> hei(N);
for (int i = 0;i < N;i++) cin >> hei.at(i);

int maxi = hei.at(0),cnt = 1;
for (int i = 1;i < N;i++) {
    if (hei.at(i) >= maxi) {
        cnt++;
        maxi = hei.at(i);
    }

}
cout << cnt << endl;

return 0;
}
