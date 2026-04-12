n = int(input())
arr = list(map(int, input().strip().split(" ")))

mod = int(1e9)+7
ans = [0]*n
sm = arr[-1]
for i in range(n-2,-1,-1):
    ans[i] = sm
    sm += arr[i]
    sm = sm%mod

fa = 0
for i in range(n):
    fa += ans[i]*arr[i]
    fa = fa%mod
    
print(fa)
    


    