import sys
import copy
def S(): return sys.stdin.readline().rstrip()
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())
INF = 1000000000000

x = I()

if(x >= 30):
    print('Yes')
else:
    print('No')