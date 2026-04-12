def main():
    s = input()
    st = set(s)
    if len(st) == 1:
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())
