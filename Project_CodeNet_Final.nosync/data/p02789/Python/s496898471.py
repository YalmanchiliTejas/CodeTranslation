from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    N, M = map(int, input().split())
    if N == M:
        print('Yes')
    else:
        print('No')


main()
