    //For higher stack size use g++ -O2 -std=c++11 -Wall -Wl,--stack=268435456 a.cpp -o a.exe in cmd
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define ll long long
    #define ld long double
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define pb push_back
    #define f first
    #define s second
    
    using namespace std;
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T;
        T=1;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            int n;
            cin>>n;
            if(n>=30)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        return 0;
    }
