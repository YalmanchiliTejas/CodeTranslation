import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, *H = map(int, read().split())

    m = 0
    ans = 0
    for h in H:
        if h >= m:
            ans += 1
            m = h

    print(ans)
    return


if __name__ == '__main__':
    main()
