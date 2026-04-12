from collections import Counter,defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,fractions
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())
def inpln(n): return list(int(sys.stdin.readline()) for i in range(n))

a,b,c,x,y = inpl()
if x>y: tmp = c*y*2+a*(x-y)
else: tmp = c*x*2+b*(y-x)
tmp = min(tmp, c*max(x,y)*2)
print(min(a*x+b*y,tmp))