MOD = 10**9 + 7

n = int(input())
A = list(map(int,input().split()))

ans = 0
S = sum(A)
for i in A:
    S -= i
    ans += i * S
    ans %= MOD
print(ans)