n = int(input())
A = list(map(int, input().split()))
ans = 0
total = sum(A[1:])

for i in range(n-1):
    ans += A[i]*total
    total -= A[i+1]
    ans %= 1000000007

print(ans)