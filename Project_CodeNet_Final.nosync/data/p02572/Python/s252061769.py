n=int(input())
l=list(map(int,input().split()))
mod=pow(10,9)+7
su=0
ans=0
for i in range(n-1,-1,-1):
	ans=(ans+((l[i]%mod)*(su%mod))%mod)%mod
	su+=l[i]
print(ans)