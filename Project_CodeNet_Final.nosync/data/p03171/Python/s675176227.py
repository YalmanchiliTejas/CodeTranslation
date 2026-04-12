#L

N=int(input())
a=list(map(int,input().split()))

S=[0]*(N+1)
for i in range(N):
    S[i+1]=S[i]+a[i]

dp=[[0]*(N+1) for _ in range(N+1)]#[l,r)の範囲が残っているときに取れる最大値

for i in range(1,N+1):#r-lの値
    for j in range(N):#lの値
        r=j+i
        if r>N:
            break
        l=j
        x=a[l]+(S[r]-S[l+1]) - dp[l+1][r]
        y=a[r-1]+(S[r-1]-S[l]) - dp[l][r-1]
        dp[l][r]=max(x,y)

print(2*dp[0][N] - S[-1] )