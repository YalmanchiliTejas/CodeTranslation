import sys,queue,copy
sys.setrecursionlimit(10**8)
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
INF = float('inf')

n,m = inpl()


if n ==m:
    print("Yes")
else:
    print("No")