MOD = 1000000007
N = int(input())
A = list(map(int, input().split()))
ans = 0
B = [0]*(N-1)
sumA = sum(A)
for i in range(1, N):
    sumA -= A[i-1]
    B[i-1] = sumA
for i in range(0, N-1):
    ans += A[i] * B[i]
    ans %= MOD
print(ans)