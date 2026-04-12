n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(n):
    A[i] %= (10**9 +7)
s = sum(A)
for i in range(n-1):
    s -= A[i]
    ans += A[i]*s
print(ans%(10**9 + 7))