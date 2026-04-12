import sys
sys.setrecursionlimit(10**6)
from math import floor,ceil,sqrt,factorial,log
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from operator import itemgetter
from fractions import gcd
mod = 10 ** 9 + 7
inf = float('inf')
ninf = -float('inf')
 
#整数input
def ii(): return int(sys.stdin.readline().rstrip()) #int(input())
def mii(): return map(int,sys.stdin.readline().rstrip().split())
def limii(): return list(mii()) #list(map(int,input().split()))
def lin(n:int): return [ii() for _ in range(n)]
def llint(n: int): return [limii() for _ in range(n)]
#文字列input
def ss(): return sys.stdin.readline().rstrip() #input()
def mss(): return sys.stdin.readline().rstrip().split()
def limss(): return list(mss()) #list(input().split())
def lst(n:int): return [ss() for _ in range(n)]
def llstr(n: int): return [limss() for _ in range(n)]

#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？
#本当に貪欲法か？ DP法では？？

a,b,c,x0,y0=mii()

tmp=10**100

x,y=x0,y0
chk=min(x//2,y//2)
ans = c*2 *(chk)*2
x-=chk*2
y-=chk*2 
if x>=1:
    ans+=min(a*x,x*c*2)
if y>=1:
    ans+=min(y*b,y*c*2)
tmp=min(ans,tmp)

x,y=x0,y0
chk=max(x//2,y//2)
ans = c*2 *(chk)*2
x-=chk*2
y-=chk*2 
if x>=1:
    ans+=min(a*x,x*c*2)
if y>=1:
    ans+=min(y*b,y*c*2)
tmp=min(ans,tmp)

x,y=x0,y0
ans =a*x+b*y
tmp=min(ans,tmp)

ans=a*x + c*2*y
tmp=min(ans,tmp)

ans=c*2*x+b*y
tmp=min(ans,tmp)

if x>=y:
    ans=a*(x-y) + c*2*y
    tmp=min(ans,tmp)   

if x<=y:
    ans=c*2*x+b*(y-x)
    tmp=min(ans,tmp)


print(tmp)