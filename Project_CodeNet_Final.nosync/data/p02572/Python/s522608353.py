mod = 10**9+7
n = int(input())
A = list(map(int,input().split()))

ans = 0
wa = 0
for i in range(n):
    wa = wa + A[i]

wa = wa%mod
wa -= A[0]    

for i in range(n-1):
    tmp = A[i]*wa%mod
    ans = tmp+ans
    wa -= A[i+1]

print(ans%mod)