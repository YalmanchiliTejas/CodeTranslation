N = int(input())
A = list(map(int, input().split()))

r = 10**9 + 7
s = sum(A)
ans = 0

for i in range(N-1):
    s -= A[i]
    ans += (s*A[i])%r
    ans %= r

print(ans)
