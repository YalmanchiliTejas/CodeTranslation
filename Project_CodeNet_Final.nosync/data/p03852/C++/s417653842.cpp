#include<bits/stdc++.h>
#include<boost/range/irange.hpp>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/algorithm/string/classification.hpp>
#include<boost/algorithm/string/split.hpp>
#include<boost/algorithm/string/join.hpp>
#include<boost/algorithm/string/replace.hpp>
#include<boost/math/tools/minima.hpp>
#include<boost/pending/disjoint_sets.hpp>
using namespace std;
using boost::irange;
using boost::multiprecision::cpp_int;
using boost::algorithm::split;
using boost::is_any_of;
using boost::algorithm::join;
using boost::algorithm::replace_all;
using boost::math::tools::brent_find_minima;
typedef long long ll;
ll max(ll a, ll b){ 
	if(a >= b) return a;
	else if(a < b) return b;
}

int main(){
  char in;
  cin >> in;
  vector<char>c{'a', 'i', 'u', 'e', 'o'};
  bool check = false;
  for(auto i: c){
    if(in == i)check = true;
  }
  string ans = (check)?"vowel":"consonant";
  cout << ans << endl;
}   

