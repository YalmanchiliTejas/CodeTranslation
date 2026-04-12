import sys
import os
import math
import bisect
import collections
import itertools

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

lcm = lambda x, y: x * y / math.gcd(x, y)

MOD = 10 ** 9 + 7
MAX = float('inf')


def f(A, B, x):
    return math.floor(A * x / B) - A * math.floor(x / B)


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N = ii()
    S = [collections.Counter(iss()) for _ in range(N)]

    values = {}
    for s in S:
        for k, v in s.items():
            values[k] = min(l[k] for l in S if k in s)

    ret = []
    for k, v in values.items():
        ret += [k] * v

    print("".join(sorted(ret)))


if __name__ == '__main__':
    main()
