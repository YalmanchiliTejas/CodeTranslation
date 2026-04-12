import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7

def LI(): return list(map(int,input().split()))
def I(): return int(input())
def LS(): return input().split()
def S(): return input()

def main():
  a,b,c,x,y=LI()

  p=a*x+b*y
  q=c*2*max(x,y)

  if x<=y:
    r=c*x*2
    r+=(y-x)*b
  else:
    r=c*y*2
    r+=(x-y)*a

  return min(p,q,r)

print(main())
