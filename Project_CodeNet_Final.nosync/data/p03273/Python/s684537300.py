import sys
from collections import Counter
from collections import deque
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

h,w=mp()
l=[]
for i in range(h):
    a=list(input())
    if a[0]!="." or len(list(set(a)))!=1:
        l.append(a)

i=0
while i<len(l[0]):
    ch=True
    for k in range(len(l)):

        if l[k][i]=="#":
            ch=False
    if ch:
        for k in range(len(l)):
            del l[k][i]
        i-=1
    i+=1
for i in range(len(l)):
    print(*l[i],sep="")