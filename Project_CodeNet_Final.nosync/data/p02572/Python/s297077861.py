N = int(input())
A = list(map(int,input().split()))
P = 10**9+7
ans = 0
S = sum(A)

for i in range(N):
    S -= A[i]
    ans += A[i]*S%P
print(ans%P)