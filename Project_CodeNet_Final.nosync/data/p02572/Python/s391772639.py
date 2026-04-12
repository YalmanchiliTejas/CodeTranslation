I=lambda:list(map(int,input().split()))
mod=10**9+7
n,=I()
l=I()
pre=l.copy()
suf=l.copy()
for i in range(n-2,-1,-1):
	suf[i]+=suf[i+1]
ans=0
#print(suf)
for i in range(n-1):
	ans+=(l[i]*suf[i+1])
	ans%=mod
print(ans)
