#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> v , v2;
int main()
{
    wcin.tie(0) , wcout.tie(0) ;
    ios_base :: sync_with_stdio (0);
    int n , i , l;
    wcin >> n;
    l = n / 2 ;
    for(i = 1 ; i <= n ; ++ i)
    {
        int number;
        wcin >> number;
        v.push_back(number);
        v2.push_back(number);
    }
    sort(v2.begin() , v2.end());
    for(i = 0 ; i < n ; ++ i)
    {
        int value , v1 = v [i] , v11 = v2 [n - l];
        if(v2 [n - l] <= v [i])
            value = v2 [n - l - 1];
        else
            value = v2 [n - l];
        wcout << value << "\n";
    }
    return 0;
}
