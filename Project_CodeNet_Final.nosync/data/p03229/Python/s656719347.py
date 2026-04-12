import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def tenka18beg_c():
    # https://atcoder.jp/contests/tenka1-2018-beginner/submissions/6799465
    inp = list(map(int, read().split()))
    N = inp[0]
    A = inp[1:]
    A.sort()

    if N % 2 == 0:
        lower = A[:N//2]
        upper = A[N//2:]
        ans = (2 * sum(upper) - upper[0]) - (2 * sum(lower) - lower[-1])
    else:
        lower = A[:N//2]
        upper = A[N//2 + 1:]
        mid = A[N//2]
        x = 2 * sum(upper) - 2 * sum(lower) - mid + lower[-1]  # 中央が +2* -1* -1* のパターン
        y = 2 * sum(upper) - 2 * sum(lower) + mid - upper[0]  # 中央が +1* +1* -2* のパターン
        ans = max(x, y)
    print(ans)

tenka18beg_c()