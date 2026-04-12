//Jai Shree Krishna
#include <bits/stdc++.h>
using namespace std;

deque<int>q1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i =0 ; i<n; i+=1) {
        int x;
        cin>>x;
        if(i%2==0)
        {
            q1.push_back(x);
        }
        else{
            q1.push_front(x);
        }
    }
    if(n%2==0){
    for(int i = 0 ;i<q1.size();i+=1)
    {
        cout<<q1[i]<<" ";
    }
    }
    else{
        reverse(q1.begin(), q1.end());
        for(int i = 0 ;i<q1.size();i+=1)
        {
            cout<<q1[i]<<" ";
        }
    }
    
    
    return 0;
}