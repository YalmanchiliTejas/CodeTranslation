
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef pair<long,ii> lii;

const long MOD = 1e9+7;
long p2(long b)
{
	if(b == 0) return 1;
	else if(b == 2) return 4;
	else if(b&1) return (p2(b-1)*2)%MOD;
	else
	{
		long temp = p2(b/2);
		return (temp*temp)%MOD;
	}
}
long geo(long a, long n)
{
	return (a*(p2(n)-1))%MOD;
}

vector<lii> vec;
long arr[100003];

int main()
{
	//ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);
	
	int n; scanf("%d", &n);	
	for(int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	long hit = 0;
	long res = 1;
	long bed = 1;
	for(int i = 1; i <= n+1; i++)
	{
		if(arr[i] == 1 || i == n+1)
		{
			long cnt = 0;
			cnt += bed;
			for(auto j : vec)
			{
				cnt += geo(j.fi,j.se.fi-j.se.se+1);
				cnt %= MOD;
			}
			// printf("i : %d\n" , i);
			// printf("	BED : %lld\n", bed);
			// printf("	CNT : %lld\n", cnt);
			if(arr[i] == 1) hit++;
			vec.clear();
			bed = 1;
			res *= cnt;
			res %= MOD;

		}
		else if(vec.size() == 0)
		{
			vec.push_back({2,{arr[i],2}});
			bed *= 2;
		}
		else if(arr[i] > arr[i-1])
		{
			for(int j = 0; j < vec.size(); j++)
			{
				vec[j].fi *= p2(arr[i]-arr[i-1]);
				vec[j].fi %= MOD;
			}
			bed *= 2; bed %= MOD;
			vec.push_back({bed,{arr[i], arr[i-1]+1}});
		}
		else
		{
			vector<lii> temp;
			bed *= 2; bed %= MOD;
			for(int j = 0; j < vec.size(); j++)
			{
				if(vec[j].se.fi > arr[i])
				{
					if(vec[j].se.se > arr[i])
					{
						bed += 2*geo(vec[j].fi,vec[j].se.fi-vec[j].se.se+1);
						bed %= MOD;
					}
					else
					{
						bed += 2*geo(vec[j].fi, vec[j].se.fi-arr[i]);
						bed %= MOD;
						temp.push_back({(vec[j].fi*p2(vec[j].se.fi-arr[i]))%MOD,{arr[i],vec[j].se.se}});
					}
				}
				else
					temp.push_back(vec[j]);
			}
			vec = temp;
		}
	}
	res *= p2(hit);
	res %= MOD;
	// printf("%lld\n", p2(1000000000));
	printf("%lld\n", res);
}










