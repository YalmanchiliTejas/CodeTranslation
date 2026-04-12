n = int(input())
A = list(map(int,input().split()))
MOD=10**9+7

s=0
S=[]
for a in A:
    s += a
    s %= MOD 
    S.append(s)    

ans=0
for i in range(n-1):
    ans += S[i]*A[i+1]
    ans %= MOD
print(ans)
