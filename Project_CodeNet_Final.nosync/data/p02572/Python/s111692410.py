N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7

sm = sum(A)

ans = 0
for s in range(len(A)-1):
    #ans += A[s]*sum(A[s+1:])
    sm -= A[s]
    ans += A[s]*sm

print(ans%mod)