mod=10**9+7
n=int(input())
a=list(map(int,input().split()))
cnt=0
cnt2=0
for x in a:
	cnt+=x**2
	cnt2+=x
	cnt%=mod
	cnt2%=mod
ans=cnt2**2%mod-cnt
if ans%2==1:
	ans+=mod
ans=ans//2%mod
print(ans)