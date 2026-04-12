import sys
input = sys.stdin.buffer.readline

N = int(input())
a = list(map(int, input().split()))

# dp[i][j] 区間a[i,j)だけ残った時点で互いの点数を一旦0とし、ゲームを最後まで続けた場合のX-Yの値
dp = [[0]*(N+1) for _ in range(N+1)] # 初期値を対角成分だけ0、その他をfloat("inf")にすると1000ms程度遅くなる

# こちらもメモ化再帰ではpypy3でも間に合わない
# j==i+1, i+2, ...とループしてdpテーブルの上三角部分を対角線と平行に埋めていく。jをi+shift_iに書き換えてshift_iについてループ
for shift_i in range(1, N+1):
    for i in range(N+1):
        if i+shift_i >= N+1:
            continue
        elif shift_i%2 == N%2: # 先手番
            dp[i][(i+shift_i)] = max(a[i] + dp[i+1][(i+shift_i)], a[(i+shift_i)-1] + dp[i][(i+shift_i)-1])
        else:
            dp[i][(i+shift_i)] = min(-a[i] + dp[i+1][(i+shift_i)], -a[(i+shift_i)-1] + dp[i][(i+shift_i)-1])

print(dp[0][N])