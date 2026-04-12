n = int(input())
A = list(map(int, input().split()))

sum_A = sum(A)

ans = 0
for i in range(n-1):
    sum_A -= A[i]
    ans += A[i] * sum_A
ans %= 10**9+7
print(ans)