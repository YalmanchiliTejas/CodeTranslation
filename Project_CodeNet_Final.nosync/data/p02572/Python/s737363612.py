n=int(input())
alist=list(map(int,input().split()))
MOD=10**9+7
nijo=0
for i in range(n):
    nijo+=(alist[i]**2)
gokei=sum(alist)

ans=(gokei**2-nijo)
ans=ans//2
ans=ans%MOD
print(ans)