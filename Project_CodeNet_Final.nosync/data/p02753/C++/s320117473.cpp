 #include <bits/stdc++.h>
#define SpeeD ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
//pair<int, int> *p=new pair<int, int>[n];
//std::vector<pair<int,int>> vp;
//v.push_back(make_pair(x,y))
//pair<int, int> p[1001];
//string *s=new string [n];
//int freq[e];
//freq[a[i]-'a']++; freq[a[i]]++;
 using namespace std;  
ll t,n,c,c3,sum,m,mn,k,r,avg;
std::vector<int >v,v2;
std::map<int, int> mp;
bool isPrime(int x)
{
for (int i=2;i*i<=x;i++)
if (x%i==0)
return false;
return true;
}
 
int main(void)
 
{
string s;
int a=0,b=0;
cin>>s;
for (int i =0;i<s.length();i++)
{
    if (s[i]=='A')a++;
    else b++;
}
if (a==3 || b==3)cout<<"No";
else cout<<"Yes";

}