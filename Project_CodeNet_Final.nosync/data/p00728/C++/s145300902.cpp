#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  int n;
  while(cin >> n, n){
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    int sum = 0;
    int i;
    for(i = 1; i < n - 1; i++) sum += s[i];
    cout << sum / (i - 1) << endl;
  }

    return 0;

}

