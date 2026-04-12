import sys
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


def main():
    X = readint()
    print('Yes' if X >= 30 else 'No')


if __name__ == "__main__":
    main()
