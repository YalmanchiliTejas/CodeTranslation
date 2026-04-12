N = int(input())
A = list(map(int,input().split()))
K = sum(A)
S = 0

for i in range(N-1):
    K = K - A[i]
    S = S + A[i]*K

ans = S%(10**9+7)

print(ans)