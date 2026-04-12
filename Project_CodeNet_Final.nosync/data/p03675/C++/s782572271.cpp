 #include <bits/stdc++.h>
using namespace std;


int A[200005];



int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int i=n;i>=1;i-=2)
        cout<<A[i]<<' ';
    for(int i=1+n%2;i<=n;i+=2)
        cout<<A[i]<<' ';

}
