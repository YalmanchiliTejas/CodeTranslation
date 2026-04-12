#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,p,h[1000010],n,max;
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    max=h[0];
    for(i=1;i<n;i++)
    {
        if(h[i]>=max)
        {
            c++;
            max=h[i];
        }
        
    }
    cout << c+1 << endl;
    return 0;

}
