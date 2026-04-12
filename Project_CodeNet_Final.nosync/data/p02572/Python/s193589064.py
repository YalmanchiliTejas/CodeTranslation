mod = 1000000007
N = int(input())
A = list(map(int, input().split()))
S = [0] # 累積和のリスト
ans = 0
for i in range(N):
    S.append(A[i] + S[i] % mod)
for i in range(N):
    sum = S[N] - S[i + 1]
    if sum < 0:
        sum += mod
    ans += A[i] * sum
print(ans % mod)


