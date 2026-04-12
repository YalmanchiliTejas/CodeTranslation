#ABC176 #F 問題 (Question F) #解説方針 #提出参考
N = int(input())
A = list(map(int, input().split()))

#DP(動的計画法)用配列
ans = [[-N] * (N+1) for _ in range(N+1)]
#初期化 (Initialization)
a0, a1 = A[:2]
ans[a0][a1] = 0
ans[a1][a0] = 0

##最大値の管理
#ans[i] の最大値を集めた配列 (0 <= i <= N)
ma = [-N] * (N+1) 
#ans の初期化に合わせて初期化
ma[a0] = 0
ma[a1] = 0
#ansの全要素の最大値、0で初期化
all_max = 0

#3, 4, 5番目の数が等しいときに加算するための変数
add = 0

#DP部分 多分 O(N ** 2)
for i in range(N - 1): 
    #3, 4, 5番目の数を a, b, c とする
    a, b, c = A[3 * i + 2], A[3 * i + 3], A[3 * i + 4]
    #3つとも等しいとき、最後の三枚を消す
    if a == b == c:
        add += 1
        continue
    Q = []
    for _ in range(3):
        a, b, c = b, c, a
        # a, b, c から残す数を2つ選ぶ
        # ans[c][c] + 1 は [c,c,a,b,c]を想定
        # all_max は DP[i][k][l]の最大値で最大化するときに対応
        Q.append((a, b, max(all_max, ans[c][c] + 1)))
        
        # a, b, c から残す数を1つ選ぶ
        for j in range(1, N + 1):
            #これまでのDP[i][k][l] (k, lのうち片方の変数として見たとき) の最大値
            val = ma[j]
            #2つの数が等しいとき
            if b == c:
                val = max(val, ans[b][j] + 1)
            Q.append((a, j, val))
            
        #配列を使いまわしているので、DP[i + 1][k][l] を DP[i][k][l]で最大化し直す必要なし
        #もしDP[i][k][l]が最大なら、maxを取る過程でこれが残る
    for i, j, val in Q:
        #DP配列の更新
        ans[i][j] = max(ans[i][j], val)
        ans[j][i] = max(ans[j][i], val)
        #最大値の管理
        ma[i] = max(ma[i], val)
        ma[j] = max(ma[j], val)
        all_max = max(all_max, val)
        
#ans の中から最大の値を見つけ出す。O(N ** 2)        
answer = 0
for i in range(1, N + 1):
    for j in range(1, N + 1):
        #最後に残った3枚が同じならもう1点加算
        if i == j == A[-1]:
            answer = max(answer, ans[i][j] + 1)
        else:
            answer = max(answer, ans[i][j])
            
print(answer + add)

