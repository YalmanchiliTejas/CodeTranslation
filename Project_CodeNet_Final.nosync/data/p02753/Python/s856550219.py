import sys


def input():
    return sys.stdin.readline()[:-1]


def main():
    s = input()
    if len(set(s)) > 1:
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()
