N = int(input())
A = list(map(int,input().split()))
cums = [0]
for a in A:
    cums.append(cums[-1] + a)

MOD = 10**9+7
ans = 0
for i in range(N-1):
    ans += A[i] * (cums[-1] - cums[i+1])
    ans %= MOD
print(ans)