
import sys
sys.setrecursionlimit(10 ** 7)
read = sys.stdin.buffer.read
inp = sys.stdin.buffer.readline
def inpS(): return inp().rstrip().decode()
readlines = sys.stdin.buffer.readlines
MOD = 10**9+7
INF = 1<<60

from bisect import bisect_right, bisect_left
def resolve():
    N = int(input())
    A = [int(input()) for _ in range(N)][::-1]

    dp = [INF]*(N+1)
    for a in A:
        ind = bisect_right(dp, a)
        dp[ind] = a

    ans = bisect_left(dp, INF)
    print(ans)

if __name__ == "__main__":
    resolve()