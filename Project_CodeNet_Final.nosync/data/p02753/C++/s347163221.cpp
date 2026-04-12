// // // // //AUTHOR:BlackBox Inc.//
// // // // #include<bits/stdc++.h>
// // // // #include<unordered_map>
// // // // #include<tr1/unordered_map>
// // // // #define ll long long
// // // // #define ull unsigned long long
// // // // #define vi vector<int>
// // // // #define vlli vector<long long int>
// // // // #define vvi vector<vector<int>>
// // // // #define vpii vector<pair<int,int>>
// // // // #define vs vector<string>
// // // // #define lin1(x) ll int x; x = scan();
// // // // #define lin2(x,y) ll int x, y; x = scan(), y = scan();
// // // // #define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
// // // // #define pb(x) push_back(x)
// // // // #define makep(x,y) make_pair(x,y)
// // // // #define mx(a,b) (a)>(b)?(a):(b)
// // // // #define mn(a,b) (a)<(b)?(a):(b)
// // // // #define fori(s,e) for(i=s;i<=e;i++)
// // // // #define forj(s,e) for(j=s;j<=e;j++)
// // // // #define fork(s,e) for(k=s;k<=e;k++)
// // // // #define rep(i,s,e) for(int i=s;i<=e;i++)
// // // // #define brep(i,s,e) for(int i=s;i>=e;i--)
// // // // #define all(x) x.begin(),x.end()
// // // // #define mem(x,y) memset(x,y,sizeof(x));
// // // // #define bits1(x) __builtin_popcount(x)
// // // // #define pi 3.14159265358979323846264338327950
// // // // #define MOD7 1000000007
// // // // #define MOD9 1000000009
// // // // #define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// // // // using namespace std;
// // // // using namespace std::tr1;

// // // // int main()
// // // // {
// // // // #ifdef RAHUL
// // // //     freopen("input.txt","r",stdin);
// // // // #endif


// // // // int t;
// // // // cin>>t;
// // // // for (int i = 0; i < t; ++i)
// // // // {
// // // //     /* code */
// // // //     int n;
// // // //     cin>>n;
// // // //     std::vector<int>rohan(n+1,0);
// // // // int t=n;

// // // //     while(t--){
// // // //         int temp;
// // // //         cin>>temp;
// // // //         rohan[temp]++;
// // // //     }
// // // //     int first=0;
// // // //     int second=0;

// // // //     for (int i = n; i>0; i--)
// // // //     {
// // // //         /* code */
// // // //         auto find=rohan[i];

// // // //         if(find==2){
// // // //             first=i;
// // // //         }
// // // //         else if(find==0){
// // // //             second=i;
// // // //         }

// // // //     }
// // // //     cout<<first<<" "<<second<<endl;

// // // //    // return 0;
// // // // }


// // // // return 0;
// // // // }
// // // #include <iostream>
// // // #include <vector>
// // // #include <algorithm>
// // // #include <iterator>
// // // using namespace std;
// // // int main() {
    
// // //     ios_base::sync_with_stdio(false);
// // //     cin.tie(nullptr);
// // //     cout.tie(nullptr);

// // //     int testCases;
// // //     cin >> testCases;
// // //     while (testCases--) {
        
// // //         int size = 0;
// // //         cin >> size;
        
// // //         std::vector<int> arr(size + 1, 0);
        
// // //         int t = size;
        
// // //         while (t--) {
// // //             int temp = 0;
// // //             cin >> temp;
// // //             arr[temp] ++;
// // //         }
        
// // //         int notPresent;
// // //         int twicePresent;
        
// // //         for (int i = size; i > 0; --i)
// // //         {
// // //             auto temp = arr[i];
// // //             if (temp == 2)
// // //             {
// // //                 twicePresent = i;
// // //             }
// // //             else if (temp == 0)
// // //             {
// // //                 notPresent = i;
// // //             }
// // //         }
        
// // //         cout << twicePresent << " " << notPresent << endl;
    
// // //     }
// // //     return 0;
// // // }

// // //AUTHOR:BlackBox Inc.//
// // #include<bits/stdc++.h>
// // #include<unordered_map>
// // #include<tr1/unordered_map>
// // #define ll long long
// // #define ull unsigned long long
// // #define vi vector<int>
// // #define vlli vector<long long int>
// // #define vvi vector<vector<int>>
// // #define vpii vector<pair<int,int>>
// // #define vs vector<string>
// // #define lin1(x) ll int x; x = scan();
// // #define lin2(x,y) ll int x, y; x = scan(), y = scan();
// // #define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
// // #define pb(x) push_back(x)
// // #define makep(x,y) make_pair(x,y)
// // #define mx(a,b) (a)>(b)?(a):(b)
// // #define mn(a,b) (a)<(b)?(a):(b)
// // #define fori(s,e) for(i=s;i<=e;i++)
// // #define forj(s,e) for(j=s;j<=e;j++)
// // #define fork(s,e) for(k=s;k<=e;k++)
// // #define rep(i,s,e) for(int i=s;i<=e;i++)
// // #define brep(i,s,e) for(int i=s;i>=e;i--)
// // #define all(x) x.begin(),x.end()
// // #define mem(x,y) memset(x,y,sizeof(x));
// // #define bits1(x) __builtin_popcount(x)
// // #define pi 3.14159265358979323846264338327950
// // #define MOD7 1000000007
// // #define MOD9 1000000009
// // #define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// // using namespace std;
// // using namespace std::tr1;

// // int main()
// // {
// // #ifdef RAHUL
// //     freopen("input.txt","r",stdin);
// // #endif
// //     int t;
// //     cin>>t;

// //     for (int i = 0; i < t; ++i)
// //     {
// //         long long rahul;
// //         cin>>rahul;
// //          std::vector<int>rohan(rahul);

// //          for (int i = 0; i < rahul; ++i)
// //          {
// //             cin>>rohan[i];
// //              /* code */
// //          }
// //          int maximum=0;
// //          int result=0;
// //          for (int i = 0; i < rahul-1; ++i)
// //          {
// //             result=rohan[i];
// //             for (int j= i+1; j < rahul; ++j)
// //             {
// //                 /* code */
// //                 if (result<=rohan[j])
// //                 {
// //                     /* code */
// //                     int k=j-i;
// //                     maximum=max(k,maximum);
// //                 }
// //             }
// //              /* code */
// //          }
// //          cout<<maximum<<"\n";
// //         /* code */
// //     }

// // return 0;
// // }

// // //AUTHOR:BlackBox Inc.//
// // #include<bits/stdc++.h>
// // #include<unordered_map>
// // #include<tr1/unordered_map>
// // #define ll long long
// // #define ull unsigned long long
// // #define vi vector<int>
// // #define vlli vector<long long int>
// // #define vvi vector<vector<int>>
// // #define vpii vector<pair<int,int>>
// // #define vs vector<string>
// // #define lin1(x) ll int x; x = scan();
// // #define lin2(x,y) ll int x, y; x = scan(), y = scan();
// // #define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
// // #define pb(x) push_back(x)
// // #define makep(x,y) make_pair(x,y)
// // #define mx(a,b) (a)>(b)?(a):(b)
// // #define mn(a,b) (a)<(b)?(a):(b)
// // #define fori(s,e) for(i=s;i<=e;i++)
// // #define forj(s,e) for(j=s;j<=e;j++)
// // #define fork(s,e) for(k=s;k<=e;k++)
// // #define rep(i,s,e) for(int i=s;i<=e;i++)
// // #define brep(i,s,e) for(int i=s;i>=e;i--)
// // #define all(x) x.begin(),x.end()
// // #define mem(x,y) memset(x,y,sizeof(x));
// // #define bits1(x) __builtin_popcount(x)
// // #define pi 3.14159265358979323846264338327950
// // #define MOD7 1000000007
// // #define MOD9 1000000009
// // #define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// // using namespace std;
// // using namespace std::tr1;

// // int main()
// // {
// // #ifdef RAHUL
// //     freopen("input.txt","r",stdin);
// // #endif

// // int n;
// // cin>>n;
// // cout<<n;

// // return 0;
// // }
// //AUTHOR:BlackBox Inc.//
// #include<bits/stdc++.h>
// #include<unordered_map>
// #include<tr1/unordered_map>
// #define ll long long
// #define ull unsigned long long
// #define vi vector<int>
// #define vlli vector<long long int>
// #define vvi vector<vector<int>>
// #define vpii vector<pair<int,int>>
// #define vs vector<string>
// #define lin1(x) ll int x; x = scan();
// #define lin2(x,y) ll int x, y; x = scan(), y = scan();
// #define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
// #define pb(x) push_back(x)
// #define makep(x,y) make_pair(x,y)
// #define mx(a,b) (a)>(b)?(a):(b)
// #define mn(a,b) (a)<(b)?(a):(b)
// #define fori(s,e) for(i=s;i<=e;i++)
// #define forj(s,e) for(j=s;j<=e;j++)
// #define fork(s,e) for(k=s;k<=e;k++)
// #define rep(i,s,e) for(int i=s;i<=e;i++)
// #define brep(i,s,e) for(int i=s;i>=e;i--)
// #define all(x) x.begin(),x.end()
// #define mem(x,y) memset(x,y,sizeof(x));
// #define bits1(x) __builtin_popcount(x)
// #define pi 3.14159265358979323846264338327950
// #define MOD7 1000000007
// #define MOD9 1000000009
// #define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// using namespace std;
// using namespace std::tr1;

// int main()
// {
// #ifdef RAHUL
//     freopen("input.txt","r",stdin);
// #endif

// ll a,b,c,d;
// cin>>a>>b>>c>>d;
// ll count=0;
// for (int i = a; i<=b; ++i)
// {
//     /* code */
//     if(i%c!=0 and i%d!=0){
//         count++;
//     }
// }
// cout<<count<<"\n";


// return 0;
// }
//AUTHOR:BlackBox Inc.//
#include<bits/stdc++.h>
#include<unordered_map>
#include<tr1/unordered_map>
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define lin1(x) ll int x; x = scan();
#define lin2(x,y) ll int x, y; x = scan(), y = scan();
#define lin3(x,y,z) ll int x, y, z; x = scan(), y = scan(), z = scan();
#define pb(x) push_back(x)
#define makep(x,y) make_pair(x,y)
#define mx(a,b) (a)>(b)?(a):(b)
#define mn(a,b) (a)<(b)?(a):(b)
#define fori(s,e) for(i=s;i<=e;i++)
#define forj(s,e) for(j=s;j<=e;j++) 
#define fork(s,e) for(k=s;k<=e;k++)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define brep(i,s,e) for(int i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define bits1(x) __builtin_popcount(x)
#define pi 3.14159265358979323846264338327950
#define MOD7 1000000007
#define MOD9 1000000009
#define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace std::tr1;

int main()
{
#ifdef RAHUL
    freopen("input.txt","r",stdin);
#endif

string s;
cin>>s;
int count=0,count1=0;
for (int i = 0; i < s.length(); ++i)
{
    if (s[i]=='A')
    {
        /* code */
        count++;
    }
    else{
        count1++;
    }
    /* code */
}

if (count >0 and count1>0)
{
    /* code */
    cout<<"Yes"<<endl;
}

else{
    cout<<"No"<<endl;
}

return 0;
}