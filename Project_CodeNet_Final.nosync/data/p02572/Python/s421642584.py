N = int(input())
A = list(map(int, input().split()))
X = 0
ans = 0
for j in range(0, N):
    X += A[j]
for i in range(0, N-1):
    X = X - A[i]
    ans += A[i] * X
ans = ans % (10**9 + 7)
print(ans)