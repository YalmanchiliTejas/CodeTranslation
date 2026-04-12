N = int(input())
A = list(map(int,input().split()))
MOD = 10**9+7

cums = [0]
for a in A:
    cums.append(cums[-1] + a)

ans = 0
for i,a in enumerate(A):
    ans += a*(cums[-1] - cums[i+1])
    ans %= MOD
print(ans)