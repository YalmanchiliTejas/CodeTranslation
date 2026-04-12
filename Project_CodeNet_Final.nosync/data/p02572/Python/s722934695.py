N = int(input())
A = list(map(int, input().split()))
a = 10**9+7
sumA = sum(A)

ans = 0

for i in range(N):
    sumA -= A[i]
    ans += A[i] * sumA
    ans %= a
    
print(ans)