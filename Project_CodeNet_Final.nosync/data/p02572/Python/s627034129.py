##C - Sum of product of pairs
##累積和
N = int(input())
A = list(map(int,input().split()))
S = sum(A)
ans = 0
for i in range(N-1):
    ans += A[i]*(S - A[i])
    S -= A[i]
print(ans % (10**9+7))