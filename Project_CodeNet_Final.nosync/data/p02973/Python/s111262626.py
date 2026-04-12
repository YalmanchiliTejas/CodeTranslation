ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
tma = lambda :tuple(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
import collections
import math
import itertools
import heapq as hq
n = ni()
A = []
for i in range(n):
    A.append(ni())
def isok(num,val):##適宜変更
    return num<val
def bisect(ls,val): ##valの関数isok(x,val)がTrueとなる一番右のindex を返す 全部Falseなら-1,Trueならlen(ls)-1
    ok = -1
    ng = len(ls)
    x = (ok+ng)//2
    while ng-ok>1:
        num = ls[x]
        if isok(num,val):
            ok = x
        else:
            ng = x
        x = (ok+ng)//2
    return ok ##一番右のTrueのindex  Trueの個数はok+1こ
INF=10**10
prev=INF
ls =[-INF]*n+[INF]*n
idx=0
for a in A:
    if a>prev:
        pass
    else:
        idx=bisect(ls,a)
    ls[idx]=a
    #print(ls,a)
print(2*n-ls.count(INF)-ls.count(-INF))
