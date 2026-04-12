n = int(input())
a = list(map(int,input().split()))
MOD = 10**9 + 7

rui = [0]*n
cur = 0
for i in range(n):
    cur = (cur+a[i]) % MOD
    rui[i] = cur
    
ans = 0
for i in range(n-1):
    ans = (ans + (a[i+1] * rui[i])) % MOD
    
print(ans)