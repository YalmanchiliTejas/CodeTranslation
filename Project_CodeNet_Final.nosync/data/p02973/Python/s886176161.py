import sys
import bisect

def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    n = int(readline())
    a = [int(readline()) for _ in range(n)]
    res = []
    for i in range(n-1, -1, -1):
        p = bisect.bisect_right(res, a[i])
        if len(res) == p:
            res.append(a[i])
        else:
            res[p] = a[i]
    print(len(res))


if __name__ == '__main__':
    solve()
