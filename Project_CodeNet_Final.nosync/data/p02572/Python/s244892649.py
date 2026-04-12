N=int(input())
A=list(map(int, input().split()))
MOD=10**9+7
tmp1 = 0
tmp2 = 0
for a in A:
    tmp1 += a
    tmp2 += (a**2)

ans = (tmp1**2 - tmp2)//2
print(ans%MOD)