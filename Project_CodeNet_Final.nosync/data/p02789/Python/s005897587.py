# ABC152a


def main():
    import sys
    input = sys.stdin.readline

    sys.setrecursionlimit(10 ** 6)
    n, m = map(int, input().split())
    if n == m:
        print('Yes')
        exit(0)
    print('No')


if __name__ == '__main__':
    main()
