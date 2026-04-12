import sys


def input():
    return sys.stdin.readline()[:-1]


def main():
    s = int(input())
    if s >= 30:
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()