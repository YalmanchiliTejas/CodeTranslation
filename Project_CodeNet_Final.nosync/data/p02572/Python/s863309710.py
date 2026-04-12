import sys


def _i(): return int(sys.stdin.readline().strip())


def _ia(): return map(int, sys.stdin.readline().strip().split())


MOD = 10**9 + 7


def main():
    n = _i()
    a = list(_ia())
    s = [0] * n
    for i in range(n-2, -1, -1):
        s[i] = s[i+1] + a[i+1]

    ans = 0
    for ai, si in zip(a, s):
        ans = (ans + (ai * si)) % MOD
    return ans


if __name__ == "__main__":
    print(main())
