# https://atcoder.jp/contests/tenka1-2018-beginner/submissions/6799465
def tenka18beg_c():
    N = int(input())
    A = [int(input()) for _ in range(N)]
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