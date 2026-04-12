N = int(input())
A = list(map(int, input().split()))
S, ans = 0, 0
for i in range(N):
    ans += S * A[i]
    S += A[i]
print(ans % 1000000007)

