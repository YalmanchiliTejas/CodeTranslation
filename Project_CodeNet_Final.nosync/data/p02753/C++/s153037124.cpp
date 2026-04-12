#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  string s;
  cin>>s;
  if(s=="AAA" || s=="BBB"){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
  return 0;
}
