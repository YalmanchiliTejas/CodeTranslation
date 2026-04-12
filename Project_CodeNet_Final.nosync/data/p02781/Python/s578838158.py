"""
# 0じゃない数字がちょうどK個
dp[i][k][s] 
上からi桁目までみて、
0じゃない数字がk個。
上i桁が一致していたら0,違っていたら1
"""
S = input()
K = int(input())
m = len(S) #桁数

dp = [[[0]*2 for j in range(5)] for i in range(110)]

# 何も決めていない状態で,1以上を使ったのが0で、0桁目まで一致している
dp[0][0][0] = 1
for i in range(m):
    for j in range(4):
        for k in range(2):
            # Sの今の桁 n_digit
            digit = int(S[i])
            i_next = i + 1            
            # 次の桁(0から9)に対して遷移を考える
            for d in range(10):
                # j : 0の数について
                if d == 0: 
                    j_next = j
                else: 
                    j_next = j + 1
                if j_next > K: 
                    #0じゃない数がKを超えたら遷移しない
                    continue
                # k : 最大を取るか問題について
                if k == 0:
                    if d > digit: 
                        continue #Nを超える
                    elif d == digit: 
                        k_next = 0 #一致
                    else: 
                        k_next = 1
                else:
                    k_next = 1 # 変わることはない
                # 今の状態から0~9の遷移先
                dp[i_next][j_next][k_next] += dp[i][j][k]

ans = sum(dp[m][K])
print(ans)