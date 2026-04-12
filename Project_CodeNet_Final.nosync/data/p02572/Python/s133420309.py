N = int(input())
A = list(map(int, input().split()))
ans = 0
Sum = sum(A)
m = 10**9+7
for i in range(N):
    ans += A[i] * (Sum - A[i])
ans = ans // 2
print(ans%m)