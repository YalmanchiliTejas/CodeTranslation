N = int(input())
A = list(map(int, input().split()))
 
ans = 0
Q = int(1e9 + 7)
 
sumA = sum(A)
 
for i in range(N-1):
    sumA -= A[i]
    ans += sumA * A[i]
    ans %= Q
 
print(ans)