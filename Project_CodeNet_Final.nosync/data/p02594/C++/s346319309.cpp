    #include <bits/stdc++.h> 
     
    using namespace std; 
    #define ll long long
    #define ld long double
   ll gcd(ll a,ll b)
   {
    if(b==0)
        return a;
    return gcd(b,a%b);
   }
    int main()
    {
        ll x;
        cin >> x;
        if(x>=30)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    