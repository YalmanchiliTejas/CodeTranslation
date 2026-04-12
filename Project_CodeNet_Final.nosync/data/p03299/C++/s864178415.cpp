//https://atcoder.jp/contests/agc026/tasks/agc026_d
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>

int f[100][101][101][2]; // [h,l,r,alt]

int constexpr MOD=1000000007;
int constexpr INV2=(MOD+1)/2;

int pow2(int exp){
	assert(exp>=0);
	int base=2,ans=1;
	while(true){
		if(exp&1)ans=ans*(int64_t)base%MOD;
		exp>>=1;if(exp==0)return ans;
		base=base*(int64_t)base%MOD;
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> a(n);for(int& x:a)std::cin>>x;

	auto vals=a;std::sort(begin(vals),end(vals));
	vals.erase(std::unique(begin(vals),end(vals)),end(vals));
	for(int& x:vals)x-=1;

	for(int hi=vals.size();hi--;){
		int const h=vals[hi];
		f[hi][n][n][0]=0;
		f[hi][n][n][1]=1;
		for(int l=n;l--;){
			f[hi][l][l][0]=0;
			f[hi][l][l][1]=1;

			int min_lr=a[l];
			if(min_lr<=h)
				continue;

			int hp=-1; // any index with height == h+1, or -1
			if(a[l]==h+1)hp=l;

			f[hi][l][l+1][0]=0;
			f[hi][l][l+1][1]=pow2(a[l]-h);

			for(int r=l+2;r<=n;++r){
				min_lr=std::min(min_lr,a[r-1]);
				if(min_lr<=h)
					continue;

				if(a[r-1]==h+1)hp=r-1;

				if(hp>=0){
					assert(f[hi][hp][hp+1][1]==2);
					if(hp!=l&&hp!=r-1)
						f[hi][l][r][1]=f[hi][l][hp][1]*(int64_t)f[hi][hp+1][r][1]
							%MOD*INV2%MOD;
					else
						f[hi][l][r][1]=f[hi][l][hp][1]*(int64_t)f[hi][hp+1][r][1]
							%MOD;

					assert(f[hi][hp][hp+1][0]==0);
					f[hi][l][r][0]=
						(
							2LL
							*
							(f[hi][l][hp][0]+f[hi][l][hp][1])
							*
							(f[hi][hp+1][r][0]+f[hi][hp+1][r][1])
							+MOD-f[hi][l][r][1]
						)%MOD;

				}else{
					assert(hi!=vals.size()-1);
					int const nexthi=hi+1;
					int const nexth=vals[nexthi];
					f[hi][l][r][0]=f[nexthi][l][r][0];
					f[hi][l][r][1]=f[nexthi][l][r][1]*(int64_t)pow2(nexth-h)%MOD;
				}
			}
		}
	}

	int h0=vals[0];
	std::cout<<(f[0][0][n][0]+f[0][0][n][1]*(int64_t)pow2(h0))%MOD<<'\n';
}


/*

given config A:
| ........... |
n of way to fill the row below (assume rect.)
1 (just flip the last col) if any 2 cons. id
2 (flip or keep) if alternate

consider top down

f[l,r,h,0|1] = num of way to fill [l..r[ with h first lay cut of (alternative?)
(assume all are > h)
1: must alternate
0: must not alternate

ans = sum f[0,n,0,all]

BASE CASE

let f[x,x,_,1] = 1 // len <= 1 : alternative
let f[x,x,_,0] = 0
let f[x,x+1,_,0] = 0
let f[x,x+1,h,1] = 2^(h[x]-h) (h[x]-h>0)


f[l,r,h,0] = f[l,r,h+1,0] if valid
f[l,r,h,1] = 2*f[l,r,h+1,1] if valid

if f[l,r,h+1,_] is not valid
then there is i in [l..r[ such that h[i]==h
consider f[l,i], f[i,i+1] and f[i+1,r]
f[l,r,h,1] = f[l,i,h,1] * f[i,r,h,1] / 2
f[l,r,h,0] = 
f[l,i,h,sum] * f[i,i+1,h,sum] * f[i+1,r,h,sum] - f[l,r,h,1]

*/