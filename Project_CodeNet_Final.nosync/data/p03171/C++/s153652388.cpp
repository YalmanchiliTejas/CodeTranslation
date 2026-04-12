#include <iostream>
#include <vector>
using namespace std;
int main()
{
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }

  vector<pair<long long int, long long int > > vec(n);

  for (long long int i = 0; i < n; ++i)
  {
     vec[i].first = arr[i];
     vec[i].second = 0;
  }

  for (long long int len = 2; len <= n; ++len)
  {
     vector<pair<long long int, long long int > > vec1;
     
     for (long long int i = 0; i < n; ++i)
     {
        long long int sp = i;
        long long int en = i + len - 1;
        if(en >= n) break;

        if(vec[i].second + arr[en] > vec[i + 1].second + arr[sp])
        {
           pair<long long int, long long int> p;
           p.first = vec[i].second + arr[en];
           p.second = vec[i].first;
           vec1.push_back(p);
        }
        else
        {
           pair<long long int, long long int> p;
           p.first = vec[i + 1].second + arr[sp];
           p.second = vec[i + 1].first;
           vec1.push_back(p);
        }
     }

     vec = vec1;

  }

  cout << vec[0].first - vec[0].second;
  return 0;
}