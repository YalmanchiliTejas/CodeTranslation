#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <iomanip>
#include <unordered_map>

using namespace std;

#define MAX 30001
#define ll long long int



int main()
{
    //freopen("input.txt", "r", stdin); // for getting input from input.txt
    //freopen("output.txt", "w", stdout);// for writing output to output.txt

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    if(s[0]==s[1] && s[1]==s[2]) cout<<"No";
    else cout<<"Yes";

}
