#include <iostream>

using namespace std;

string submit(int n, int m){
    if(n == m)
        return "Yes";
    return "No";
}
int main()
{
    int n, m;
    cin>>n>>m;
    cout<<submit(n, m);

    return 0;
}
