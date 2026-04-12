#include<iostream>
#include<istream>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    int l;
    int i=0;
    while(cin>>l){
        v[i] = l;
        ++i;
    }
    int temp = v[0];
    int counter = 0;
    for(int i = 0 ; i < N; ++i){
        if(v[i] >= temp){
            temp = v[i];
            ++counter;
        }
    }
    cout << counter << endl;
  return 0;
}
