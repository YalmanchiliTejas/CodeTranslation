

mod=10**9+7

sm=0

n=int(input())
a=list(map(int,input().split()))

ans=0

for i in a:
	sm+=i
	sm%=mod

for i in a:
	sm-=i
	sm+=mod
	sm%=mod
	ans+=(i*sm)%mod
	ans%=mod

print(ans)

