#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dump(vector<long long> hoge) {
    int n = hoge.size(); for(int i = 0; i < n; ++i){ cout << hoge[i] << " "; } cout << endl;
}

int main(int, char**) {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> a(n);
    vector<pair<long long, int>> p;
    p.reserve(n+1);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        p.push_back(make_pair(a[i], i));
    }

    sort(p.begin(), p.end());

    vector<long long> nums(n);
    for(int i = 0; i < n; ++i){
      int original_ind = p[i].second;
      int rank = i;
      nums[original_ind] = i;
    }

    int l = n-1;
    int amed = p[(l+1)/2].first;
    int bmed = p[(l+1)/2 - 1].first;

    for(int i = 0; i < n; ++i){
      // cout << nums[i] << " ";

      if(nums[i] < (l+1)/2) {
        cout << amed;
      } else {
        cout << bmed;
      }

      cout << endl;
    }

}
