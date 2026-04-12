N = int(input())
A = list(map(int, input().split()))

mx = 10**9 + 7

su = sum(A)
ans = 0

for i in range(N):
    su -= A[i]
    ans += A[i]*su

print(ans % mx)