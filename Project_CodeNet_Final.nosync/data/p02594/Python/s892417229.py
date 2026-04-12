import sys
sys.setrecursionlimit(10**7)
def input(): return sys.stdin.readline().rstrip()


def main():
    if int(input()) >= 30:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()