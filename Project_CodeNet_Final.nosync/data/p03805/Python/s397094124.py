import sys
from itertools import permutations
INPUT = lambda: sys.stdin.readline().rstrip()
MAP = lambda: map(int, INPUT().split())
sys.setrecursionlimit(10 ** 9)


def main():
    N, M = MAP()
    edges = set()

    for _ in range(M):
        u, v = MAP()
        edges |= {(u-1, v-1), (v-1, u-1)}

    print(sum(all((u, v) in edges for u, v in zip(p, p[1:])) for p in permutations(range(N)) if p[0] == 0))


if __name__ == '__main__':
    main()