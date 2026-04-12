    #include "bits/stdc++.h"
    using namespace std ;
    int main()
    {
        bool f1 = false , f2 = false ;
        string a ;
        cin >> a ;
        for(auto i : a) f1 = f1 ||(i=='A') ,f2 = f2 ||(i=='B');
        if(f1&&f2) cout << "Yes\n" ;
        else cout << "No" ;
    }