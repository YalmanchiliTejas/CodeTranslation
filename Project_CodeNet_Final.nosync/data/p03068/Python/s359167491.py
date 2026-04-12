import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N = int(readline())
    S = input()
    K = int(readline())

    letter = S[K - 1]

    res = ""
    for x in S:
        if x == letter:
            res += letter
        else:
            res += "*"

    print(res)


if __name__ == '__main__':
    main()
