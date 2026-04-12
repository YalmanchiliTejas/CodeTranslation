N = int(input())
A = list(map(int, input().split(' ')))
const = 1000000007
ans = 0
total = sum(A)
for i in range(N):
    total -= A[i]
    ans += A[i] * total
print(ans%const)