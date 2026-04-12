MOD = 10**9 + 7
N = int(input())
A = list(map(int,input().split()))
ans = 0
com = 0
for i in range(N):
    ans += com*A[i]
    com += A[i]
    ans %= MOD
    com %= MOD
print(ans)