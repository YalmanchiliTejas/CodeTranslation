#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     multimap<int,int> mp2;
     map<int,int> mp;
     int n;
     cin>>n;
     int j,arr[n];
     for(j=0;j<n;j++)
        cin>>arr[j];
     multiset<int> st;
     int ptr=1;
     mp[ptr]=arr[0];
     mp2.insert({arr[0],ptr});
     st.insert(arr[0]);
     for(j=1;j<n;j++)
     {
		 int val=*st.begin();
		 if(val>=arr[j])
		 {
			 ptr++;
			 mp[ptr]=arr[j];
			 mp2.insert({arr[j],ptr});
			 st.insert(arr[j]);
		 }
		 else
	     {
			 auto it=st.lower_bound(arr[j]);
			 it--;
			 val=*it;
			 auto it2=mp2.find(val);
			 int index=it2->second;
			 mp[index]=arr[j];
			 st.erase(it);
			 st.insert(arr[j]);
			 mp2.erase(it2);
			 mp2.insert({arr[j],index});
		 }
	 }
	 cout<<mp.size()<<endl;
}
