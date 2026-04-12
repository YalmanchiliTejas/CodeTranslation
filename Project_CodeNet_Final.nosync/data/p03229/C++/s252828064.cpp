#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll s(vector<int>A)
{
	ll res=0;
	queue<int> q;
	map<int,bool>m;
	int l=0,r=A.size()-1;
	q.push(l);
	q.push(l);
	l++;
	while(!q.empty())
	{
		if(r<l)
		{
			break;
		}
		int np=q.front();q.pop();
		if(abs(r-np)>abs(l-np))
		{
			res+=abs(A[r]-A[np]);
			if(!m[r])
			{
				m[r]=true;
				q.push(r--);
			}
		}
		else
		{
			res+=abs(A[l]-A[np]);
			if(!m[l])
			{
				m[l]=true;
				q.push(l++);
			}

		}
	}
	return res;
}

ll s2(vector<int>A)
{
	ll res=0;
	queue<int> q;
	map<int,bool>m;
	map<int,bool>f;
	int l=0,r=A.size()-1;
	q.push(r);
	q.push(r);
	r--;
	while(!q.empty())
	{
		if(r<l)
		{
			break;
		}
		int np=q.front();q.pop();
		if(abs(r-np)>abs(l-np))
		{
			res+=abs(A[r]-A[np]);
			if(!m[r])
			{
				m[r]=true;
				q.push(r--);
			}
		}
		else
		{
			res+=abs(A[l]-A[np]);
			if(!m[l])
			{
				m[l]=true;
				q.push(l++);
			}
		}
	}
	return res;
}


int main()
{
	int N;
	cin>>N;
	vector<int>A;
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		A.push_back(a);
	}
	sort(A.begin(),A.end());
	cout<<max(s(A),s2(A))<<endl;
	
}