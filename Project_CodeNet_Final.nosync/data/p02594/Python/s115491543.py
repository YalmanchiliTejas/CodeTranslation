import sys
sys.setrecursionlimit(10**6)


def main(input, print):
    X = int(input())
    if X >= 30:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main(sys.stdin.readline, print)
