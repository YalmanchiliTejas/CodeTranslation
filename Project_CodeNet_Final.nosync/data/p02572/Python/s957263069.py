mod = 10 ** 9 + 7
N = int(input())
A = list(map(int,input().split()))
B = [A[0] % mod]
for i in range(N-1):
    B.append((B[-1] + A[i+1]) % mod)
ans = 0
for i in range(N-1):
    ans += A[-i-1] * B[-i-2]
    ans %= mod

print(ans)