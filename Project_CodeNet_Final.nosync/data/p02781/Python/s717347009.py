## ABC154E

import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


M = 10**9+7 # 出力の制限
N = 100 # 必要なテーブルサイズ

def cmb(n, r, M):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return (g1[n] * g2[r] * g2[n-r]) % M

g1 = [None] * (N+1) # 元テーブル
g2 = [None] * (N+1) #逆元テーブル
inverse = [None] * (N+1) #逆元テーブル計算用テーブル
g1[0] = g1[1] = g2[0] = g2[1] = 1
inverse[0], inverse[1] = [0, 1] 

for i in range( 2, N + 1 ):
    g1[i] = ( g1[i-1] * i ) % M 
    inverse[i] = ( -inverse[M % i] * (M//i) ) % M # ai+b==0 mod M <=> i==-b*a^(-1) <=> i^(-1)==-b^(-1)*aより
    g2[i] = (g2[i-1] * inverse[i]) % M 



n = input()
k = int(input())
l = len(n)

dp0 = [[0]*(k+1) for _ in range(l+1)] # i桁目まででNより小さく、非零がjの個数
dp1 = [[0]*(k+1) for _ in range(l+1)] # i桁目でNと同じで、非零がjの個数
dp1[0][0] = 1

if k>l:
    ans = 0
else:
    for i in range(1,l+1):
        for j in range(k+1):
            c = int(n[i-1])
            if j>=1:
                dp0[i][j] += 9 * dp0[i-1][j-1]
            dp0[i][j] += dp0[i-1][j]            
            if c>=1:
                dp0[i][j] += dp1[i-1][j]
                if j>=1:
                    dp0[i][j] += (c-1) * dp1[i-1][j-1]
                
            if c==0:
                dp1[i][j] += dp1[i-1][j]
            elif j>=1:
                dp1[i][j] += dp1[i-1][j-1]
                
ans = dp0[l][k] + dp1[l][k]
print(ans)