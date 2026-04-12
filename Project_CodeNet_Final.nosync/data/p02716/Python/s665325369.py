from itertools import accumulate


def solve_odd(n, aaa):
    INF = 10 ** 18
    p0, p1, p2, a0, a1, a2 = INF, INF, INF, INF, INF, 0
    for a in aaa:
        n2 = min(INF, p2 + a)
        n1 = min(INF, a2 + a, p1 + a)
        n0 = min(INF, a1 + a, p0 + a)
        p0, p1, p2, a0, a1, a2 = a0, a1, a2, n0, n1, n2
    return sum(aaa) - min(p0, a1)


def solve_even(n, aaa):
    fwd = [0] + list(accumulate(aaa[::2]))
    bwd = [0] + list(accumulate(aaa[::-2]))
    bwd.reverse()
    return max(f + b for f, b in zip(fwd, bwd))


n = int(input())
aaa = list(map(int, input().split()))
if n % 2 == 0:
    print(solve_even(n, aaa))
else:
    print(solve_odd(n, aaa))
