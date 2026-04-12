mod = 10**9+7
n = int(input())
A = tuple(map(int, input().split()))
B = [0]*n
B[0] = A[0]
for i in range(1, n):
    B[i] = B[i-1] + A[i]
    B[i] %= mod
ans = 0
for i in range(1, n):
    a = A[i]
    a *= B[i-1]
    a %= mod
    ans += a
    ans %= mod
print(ans)