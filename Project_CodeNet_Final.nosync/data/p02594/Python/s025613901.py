import sys
readline = sys.stdin.readline

def solve():
    X = int(readline())

    if X >= 30:
        print('Yes')
    else:
        print('No')

solve()