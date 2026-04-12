import sys

sys.setrecursionlimit(10 ** 7)
rl = sys.stdin.readline


def solve():
    s = set(list(input()))
    if len(s) == 1: 
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':
    solve()
