n = int(input())
k = int(input())
ns = str(n)
digits = len(ns)
dp = [[[0, 0, 0, 0] for i in range(2)] for i in range(digits + 1)]
#dp[i + 1][flag][j]:= 上からi桁目までで条件を満たす数
#flag = 0: 取り出したi桁目までが一致している(次の桁の制約ができる)
#j: 0~3　出てきた0以外の数字の数

dp[0][0][0] = 1
for s in range(digits):
    for t in range(2):
        for u in range(4):
            temp = dp[s][t][u]
            if temp == 0:continue

            if t == 0:
                #上位の桁による制約を受ける

                for i in range(int(ns[s]) + 1):
                    if i == int(ns[s]):
                        if i == 0:
                            dp[s + 1][t][u] += temp
                        elif i != 0 and u + 1 < 4:
                            dp[s + 1][t][u + 1] += temp

                    else:
                        if i == 0:
                            dp[s + 1][t + 1][u] += temp
                        elif i != 0 and u + 1 < 4:
                            dp[s + 1][t + 1][u + 1] += temp

            else:
                #上位の桁からの制約がない
                for i in range(10):
                    if i == 0:
                        dp[s + 1][t][u] += temp
                    elif i != 0 and u + 1 < 4:
                        dp[s + 1][t][u + 1] += temp

ans = dp[-1][0][k] + dp[-1][1][k]
print(ans)