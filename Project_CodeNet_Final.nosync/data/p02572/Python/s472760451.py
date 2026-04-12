mod = 10**9+7
N = int(input())
A = list(map(int, input().split()))

#累積和のリストを作成
S = [0]*(N+1)
ans = 0
for i in range(N):
    S[i+1] = A[i] + S[i]%mod

#累積和って感じですね
for i in range(N):
    sum = S[N] - S[i + 1]
    if sum < 0:
        sum += mod
    ans += A[i] * sum

print(ans % mod)