import sys
# input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)
MOD = 10 ** 9 + 7

N = list(input())
n = len(N)
K = int(input())

dp1 = [[0] * (K + 1) for _ in range(n + 1)] #N以下が確定していて、0以外の数をk個使ったとき
dp2 = [0] * (n + 1) #N以下が確定していないときの0以外の数の個数

for i in range(n):
    a = int(N[i])

    if a != 0:
        dp2[i + 1] = dp2[i] + 1
    else:
        dp2[i + 1] = dp2[i]
    
    #0を使うことで0以外の数が増えないパターン
    for k in range(K + 1):
        dp1[i + 1][k] = dp1[i][k]

    #0以外の数を使うことで0以外の数が増えるパターン
    for k in range(K):
        dp1[i + 1][k + 1] += dp1[i][k] * 9
    
    #今回でN以下が確定するパターン
    tmp = dp2[i] #確定する前までに0以外の数を何個使っているか
    if a == 0: #今回でN以下が確定することはない
        continue
    else:
        if tmp > K: #すでにK個以上の0以外の数を使っているとき
            continue
        else:
            if tmp == K: #ちょうどK個使っている時
                dp1[i + 1][tmp] += 1 #0を使うしかない
            else:
                dp1[i + 1][tmp] += 1 #0を使うしかない
                dp1[i + 1][tmp + 1] += (a - 1) #N以下を確定させるためaは使えない

ans = dp1[n][K]
if dp2[n] == K:
    ans += 1

print (ans)

# print (dp1)
# print (dp2)