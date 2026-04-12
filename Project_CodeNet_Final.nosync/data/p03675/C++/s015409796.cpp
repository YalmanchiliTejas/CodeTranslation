/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    
    cin >> arr[n/2];
    int temp = 1;
    int sing = -1;
    
    for(int i = 0; i < n - 1; ++i)
    {
        
        cin >> arr[n/2 + temp*sing];
        
        sing*=-1;
        if(i%2 == 1)
        {
            temp++;
        }
    }
    
    
    
    if(n%2 == 1)
    {
        for(int i = n-1; i >=0; --i)
        {
            cout << arr[i] << " "; 
        }
    }
    else{
        for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " "; 
    }
    }
    
    return 0;
}
