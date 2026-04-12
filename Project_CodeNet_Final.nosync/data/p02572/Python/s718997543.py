n=int(input())
L=list(map(int,input().split()))
mod=10**9+7
tmp1=sum(L)
tmp2=0
for i in range(n):
    tmp2+=(L[i])**2
print(((tmp1**2-tmp2)//2)%mod)