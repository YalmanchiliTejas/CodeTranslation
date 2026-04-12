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

  l=[]
  l.append(a*x+b*y)
  l.append(c*x*2+b*max(0,y-x))
  l.append(c*y*2+a*max(0,x-y))
  l.append(c*max(x,y)*2)
  return min(l)

print(main())
