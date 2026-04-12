    /*****************************************************************\
    |     IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL       |
    |                                                                 |
    |     Author     : Mahabub Rahman                                 |
    |     Email      : mahabubrahman618@gmail.com                     |
    |     University : Comilla University, Bangladesh		          |
    |                  Department of Computer Science & Engineering   |
    \*****************************************************************/


    /*...................................Data_Types............................................*/
    #include<bits/stdc++.h>

    using namespace std;
    #define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
    #define       ll                  long long int
    #define       ull                  unsigned long long int
    #define       veci                 vector<int>
    #define       vecc                 vector<char>
    #define       vecs                 vector<string>
    #define       vecl                 vector<long long int>
    #define       vecp                 vector<  pair<int,int> >
    #define       mapstrint            map< string , int >
    #define       mapstrstr            map< string , string >
    #define       mapint               map< int, int >
    #define       pb                   push_back
    #define       pob                  pop_back
    #define       mp                   make_pair
    ////============ CONSTANT ===============////
    #define mx9   1000000009
    #define mx7   10000007
    #define mx6   1000006
    #define mx5   100005
    #define inf   1<<30                                           //infinity value
    #define eps   1e-9
    #define mx    (65540)
    #define mod   1000000007
    ////=====================================////

    long double PI = acosl(-1);
    bool compare_int(int a, int b) //This function is use for descending order.
    {
        return (a>b);
    }
    bool compare_string (string a, string b)
    {
        return a.size() < b.size();
    }
    bool compare_pair(const pair<int,int> &a,
                  const pair<int,int> &b)
    {
        if(a.second==b.second) return a.first>b.first;
        else return (a.second > b.second);
    }
    ll fact(ll n)
    {
        if(n==0 || n==1) return 1;
        else return n*fact(n-1);
    }

    ////======================================////
    /*bool check(int n)
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }*/

    int32_t main()
    {
        FastIO;
        string s;
        cin >> s;
        if(s[0]==s[1] && s[1]==s[2])
        {
            cout << "No\n";
        }
        else cout << "Yes\n";
        
    }
