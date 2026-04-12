#include<bits/stdc++.h>
#define int long long
using namespace std ;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

    bool a = false , b = false ;
    string s ;
    cin >> s ;
    for(int i = 0 ; i < 3; ++i)
    {
    	if(s[i] == 'A')
    		a =true; 
    	else 
    		b = true ; 

    }
    if(a && b)
    	cout << "Yes" ;
    else
    	cout << "No" ; 	                                   
}    
















