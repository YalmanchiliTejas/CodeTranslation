
import sys,collections
#sys.stdin=open("data.txt")
input=sys.stdin.readline

n=int(input())

d=collections.deque()

c=0
for i in map(int,input().split()):
    if c==0:
        d.append(i)
        c=1
    else:
        d.appendleft(i)
        c=0

if c==1:
    l=list(d)[::-1]
else:
    l=list(d)

print(" ".join(map(str,l)))
