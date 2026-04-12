import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from collections import deque
    from itertools import combinations

    h, w = map(int, readline().split())
    a = list()
    cnt = 0
    for i in range(h):
        s = input()
        cnt += s.count("#")
        a.append(s)

    if cnt != (h + w - 1):
        return print("Impossible")

    for per in combinations(range(h + w - 2), h - 1):
        cr, cc = 0, 0
        for i in range(h + w - 2):
            if i in per:
                cr += 1
            else:
                cc += 1
            if a[cr][cc] == ".":
                break
            if (cr, cc) == (h - 1, w - 1):
                return print("Possible")
    return print("Impossible")


if __name__ == '__main__':
    main()
