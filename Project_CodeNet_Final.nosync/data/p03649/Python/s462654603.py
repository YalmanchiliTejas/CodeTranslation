import sys


def bisect_left_callable(fn, x, lo, hi):
    """
    lo から hi-1 のうち、fn の結果が x 以上となる、最も左の値
    bisect.bisect_left と同じ
    https://docs.python.org/ja/3/library/bisect.html
    :param callable fn:
    :param x:
    :param int lo: 最小値
    :param int hi: 最大値 + 1
    :return: lo <= ret <= hi
    """
    while lo < hi:
        mid = (lo + hi) // 2
        if fn(mid) < x:
            lo = mid + 1
        else:
            hi = mid
    return lo


sys.setrecursionlimit(100000)
INF = float('inf')

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))

MAX = 10 ** 20


def check(k):
    """
    :param int k:
    :return: k 回操作して条件を満たせば 0、k が大きすぎたらプラス、小さすぎたらマイナス
    """
    # k を全体に足す
    # N + 1 をちょうど k 回引ければそれが答え
    li = [a + k for a in A]
    sub = 0
    for a in li:
        sub += (a + 1) // (N + 1)
    return k - sub


# このへんに答えがある
ans = bisect_left_callable(check, 0, 0, MAX)
# このへん小さい順に全部調べる（あたまわるい）
ans = max(0, ans - 10000)
while check(ans) != 0:
    ans += 1
print(ans)
