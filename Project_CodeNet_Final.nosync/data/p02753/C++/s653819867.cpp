/*******Bismillahir-Rahmanir-Rahim**********/
/*
Name         : Abu Rifat Muhammed Al Hasib
Institution  : University of Barisal, Bangladesh
Github       : abu-rifat
Codeforces   : AbuRifatMuhammed
AtCoder      : aburifat
codechef     : aburifat
SPOJ         : abu_rifat
UvaOJ        : aburifat
DevSkill     : abu_rifat
lightoj      : Abu Rifat Muhammed Al Hasib
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com
*/

/*
Contest         : Beginner Contest 158
Online Judge    : AtCoder
Solving Method  :
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 250009
#define pb push_back


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t;
    t=1;
    //cin>>t;
    for(ll T=1;T<=t;T++)
    {
        string s;
        cin>>s;
        map<char,ll>m;
        for(ll i=0; i<s.size();i++){
            m[s[i]]++;
        }
        if(m['A']==0|m['B']==0){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}

/***********Alhamdulillah***********/

