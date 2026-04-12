N = int(input())
A = list(map(int,input().split()))

mod = 1000000007

AS = sum(A)
S = [AS]
tmp = 0
for i in range(N):
    tmp += A[i]
    S.append(AS - tmp)

ans = 0
for i in range(N):
    ans += A[i]*S[i+1]

print(ans%mod)
