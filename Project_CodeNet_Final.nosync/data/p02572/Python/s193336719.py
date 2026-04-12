n = int(input())
A = list(map(int, input().split()))

ans = 0
cumsum = 0

for i in range(n-1):
    cumsum += A[n-i-1]
    ans += (A[n-i-2] * cumsum)
    ans %= 1000000007

print(ans)