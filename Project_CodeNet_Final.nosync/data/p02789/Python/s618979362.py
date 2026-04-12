import sys
input = sys.stdin.readline

n, m = [int(i) for i in input().split()]

def cond():
    if n == m:
        print('Yes')
    else:
        print('No')

cond()
