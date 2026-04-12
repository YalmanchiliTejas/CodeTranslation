def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)
    x = int(input())
    if x >= 30:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()