import sys
# 許容する再帰処理の回数を変更
sys.setrecursionlimit(10**5+10)
# input処理を高速化する
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
a = list(map(int, input().split()))

#dp[i][j]はa[i]からa[j]が残ってる状態から取った時のX-Y
dp = [[0 for _ in range(N+1)] for _ in range(N+1)]

#forは状態の配列の長さを増やしつつ回す
for gap in range(0, N):
    for left in range(N - gap):
        player = (N-gap-1) % 2
        right = left + gap

        if player == 0:
            if gap == 0:
                dp[left][right] = a[left]
                continue
            dp[left][right] = max(dp[left+1][right] + a[left], dp[left][right-1] + a[right])

        else:
            if gap == 0:
                dp[left][right] = -a[left]
                continue
            dp[left][right] = min(dp[left+1][right] - a[left], dp[left][right-1] - a[right])

print(dp[0][N-1])