from bisect import bisect_left, bisect_right
import sys
input = sys.stdin.readline

INF = float('inf')

N = int(input())
As = [-int(input()) for _ in range(N)]

def getLenLNDS(As):
    dp = [-INF]
    for A in As:
        if dp[-1] <= A:
            dp.append(A)
        else:
            i = bisect_right(dp, A)
            dp[i] = A
    return len(dp)-1

ans = getLenLNDS(As)

print(ans)
