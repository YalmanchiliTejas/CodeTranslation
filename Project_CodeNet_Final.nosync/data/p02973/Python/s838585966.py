import sys
from bisect import bisect_right, bisect_left

def solve():
    input = sys.stdin.readline
    N = int(input())
    A = [int(input()) for _ in range(N)]
    col = [1] * N
    col[0] = -A[0]
    for a in A[1:]:
        index = bisect_right(col, -a)
        col[index] = -a
        #print(col, index)
    ans = bisect_right(col, 0)
    print(ans)

    return 0

if __name__ == "__main__":
    solve()