N = int(input())
A = list(map(int, input().split()))
cum_A = [0]
mod = (10 ** 9) + 7
for i in range(N):
    cum_A.append((cum_A[i] + A[i]))

ans = 0
for i, a in enumerate(A):
    #print(f"{a}*{cum_A[N] - cum_A[i + 1]}")
    ans += a * ((cum_A[N] - cum_A[i + 1]) % mod)
    ans %= mod
    #print(ans)
print(ans)


