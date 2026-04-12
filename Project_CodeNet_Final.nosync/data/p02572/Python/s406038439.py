N = int(input())
A = list(map(int,input().split()))
K = sum(A)-A[0]
ans = 0
for i in range(N-1):
    ans += A[i]*K
    ans = ans%(10**9+7)
    K -= A[i+1]
print(ans)