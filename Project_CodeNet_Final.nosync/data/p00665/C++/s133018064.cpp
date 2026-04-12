#include <bits/stdc++.h>

using namespace std;


struct BinaryIndexedTree
{
  vector< int > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  int sum(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main()
{
  long long N, M, K, L;
  char buff[12];

  while(scanf("%lld %lld %lld %lld", &N, &M, &K, &L), N) {

    vector< pair< int, string > > data(N);
    vector< int > toint(N);
    vector< string > priority(N);
    unordered_map< string, int > vv;
    vector< bool > like(N, false);

    for(int i = 0; i < N; i++) {
      int x;
      scanf(" %s %d", buff, &x);
      data[i] = make_pair(-x, buff);
      priority[i] = data[i].second;
    }
    sort(begin(priority), end(priority));
    sort(begin(data), end(data));


    for(int i = 0; i < N; i++) {
      toint[i] = lower_bound(begin(priority), end(priority), data[i].second) - begin(priority);
      vv[data[i].second] = i;
      data[i].first *= -1;
    }

    for(int i = 0; i < M; i++) {
      scanf("%s", buff);
      like[vv[buff]] = true;
    }

    BinaryIndexedTree bit(N);

    long long right = K, bottom = 0, up = 0;
    long long sz = 0, ret = 0, pre = -1;

    for(int i = 0; i < K; i++) {
      ret += like[i];
    }

    for(int i = K - 1; i >= 0; i--) {
      if(!like[i]) {
        while(right < N && !like[right]) ++right;
        if(right == N) break;
        L -= data[i].first - data[right].first;
        if(~pre) {
          L -= bottom * (data[i].first - pre);
          L -= up * (data[i].first - pre - 1); // kore sugoi
        }
        bit.add(toint[right], 1);
        bottom = bit.sum(toint[i]);
        up = bit.sum(N - 1) - bottom;
        pre = data[i].first;
        sz = 0;
        L -= up;
        if(L < 0) break;
        ++ret;
        ++right;
      } else {
        if(i == 0) break;
        bit.add(toint[i], 1);
        L -= ++sz * (data[i - 1].first - data[i].first);
      }
    }

    printf("%lld\n", ret);
  }

}