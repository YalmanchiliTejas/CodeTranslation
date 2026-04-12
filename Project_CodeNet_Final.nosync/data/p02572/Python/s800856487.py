N = int(input())
A = list(map(int, input().split()))

M = 10**9 + 7

Total = sum(A) -A[0]

ans = 0

for i in range(N-1):
    ans += A[i] * Total
    ans = ans % M
    Total -= A[i+1]

print(ans)