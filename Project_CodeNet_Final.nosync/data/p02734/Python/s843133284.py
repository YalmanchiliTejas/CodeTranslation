import sys
input = sys.stdin.readline

N,S=map(int,input().split())
A=list(map(int,input().split()))
mod=998244353

DP=[0]*(S+1)

# 多項式の考え方が分かりやすい.
# 多項式を使わないなら,
# DP[j] := 終端がiになる区間について, S=jのときのF(*,i)の和
# を更新していくと考えれば良いのかな...

DP[0]=1
ANS=0
for a in A:
    for i in range(S-a,-1,-1):
        DP[i+a]+=DP[i]
    DP[0]+=1
    ANS+=DP[S]
    
print(ANS%mod)