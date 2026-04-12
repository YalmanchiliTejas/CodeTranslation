#EDPC L メモ化再帰じゃTLEで通らないのでやり直し

N=int(input())
a=list(map(int,input().split()))

#dp[l][r]:=区間[l,r]が残っている時の(直後の人の最終的な得点-そうじゃない方の最終的な得点）

dp=[[-1]*N for _ in range(N)]

for k in range(N):
    dp[k][k]=a[k]

for r in range(1,N):
    for l in reversed(range(r)):
        dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1])

print(dp[0][N-1])