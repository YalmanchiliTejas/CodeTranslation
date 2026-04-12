import sys
def input():
    return sys.stdin.readline()[:-1]

N,M = map(int,input().split(' '))
if N==M:
    print('Yes')
else:
    print('No')