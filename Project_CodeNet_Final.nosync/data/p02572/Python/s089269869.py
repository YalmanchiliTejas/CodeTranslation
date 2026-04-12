N=int(input())
A=list(map(int,input().split()))

mod=10**9+7

inv = pow(2,mod-2,mod)

tmp1=0
for i in range(N):
    tmp1+=A[i]
    tmp1%=mod

tmp2=0
for i in range(N):
    tmp2+=A[i]**2
    tmp2%=mod

res = tmp1**2-tmp2
res %= mod
res *= inv
res %= mod

print(res)
