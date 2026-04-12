n = int(input())
A = list(map(int, input().split()))

s = sum(A)
ans = 0
for i in range(n-1):
    s -= A[i]
    ans = (ans + A[i] * s) % int(1e9 + 7)

print(ans)
