#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a,b;
int main()
{
    int n,temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
   }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cout<<lower_bound(a.begin(), a.end(), temp)-a.begin()<<endl;
    }
}
