#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    string ans;

    if(n==m)
        ans = "Yes";
    else
        ans = "No";    

    std::cout << ans << std::endl;
}

