# https://scrapbox.io/ganariya/AtCoderDP%E3%81%BE%E3%81%A8%E3%82%81%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88_L%E5%95%8F%E9%A1%8C_%E3%80%8CDeque%E3%80%8D

from collections import deque
N = int(input())
a = deque(list(map(int,input().split())))
#区間dp
#dp[i][j] : [i,j)番目の要素が残っている状態からの最適解

def Sente(i,j):
    return True if (N-(j-i))%2 == 0 else False

dp = [[0]*(N+1) for _ in range(N+1)]
for i in reversed(range(N)):
    for j in range(i+1,N+1):
        if Sente(i,j):
            dp[i][j] = max(a[i] + dp[i+1][j], a[j-1] + dp[i][j-1])
        else:
            dp[i][j] = min(-a[i] + dp[i+1][j], -a[j-1] + dp[i][j-1])
print(dp[0][N])
