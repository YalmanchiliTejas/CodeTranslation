import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    from collections import Counter

    n = int(readline())
    s = input()
    cur = Counter(s)

    for i in range(n - 1):
        s = input()
        nx = Counter(s)
        cur = cur & nx

    a = list(cur.elements())
    a.sort()

    print("".join(a))


if __name__ == '__main__':
    main()
