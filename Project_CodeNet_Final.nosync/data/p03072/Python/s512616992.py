import sys

INPUT = lambda: sys.stdin.readline().rstrip()
INT = lambda: int(INPUT())
LIST = lambda: list(map(int, INPUT().split()))

sys.setrecursionlimit(10 ** 9)


def main():
    N = INT()
    H = LIST()

    cnt = 1
    for i in range(N-1):
        if H[i+1] >= H[i]: cnt += 1
        else: H[i+1] = H[i]

    print(cnt)


if __name__ == '__main__':
    main()