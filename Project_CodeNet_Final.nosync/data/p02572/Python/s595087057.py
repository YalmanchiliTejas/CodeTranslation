from itertools import accumulate


def solve(string):
    _, *a = map(int, string.split())
    ac = list(accumulate(a))
    ans = 0
    for _a, _c in zip(a, ac):
        ans = (ans + _a * (ac[-1] - _c)) % (10**9 + 7)
    return str(ans)


if __name__ == '__main__':
    import sys
    print(solve(sys.stdin.read().strip()))
