import sys
from collections import defaultdict
from collections import deque
from copy import deepcopy

def perm(h,r):
    n=len(r)
    stack=[]
    if n==0:
        return [h]
    for i in range(n):
        nh=h+[r[i]]
        nr=r[:i]+r[i+1:]
        stack+=perm(nh,nr)
    return stack
        
def main():
    n,m=map(int,input().split())
    e=[tuple(map(int,input().split())) for _ in range(m)]
    gm=[[0]*n for _ in range(n)]
    for edge in e:
        gm[edge[0]-1][edge[1]-1]=1
        gm[edge[1]-1][edge[0]-1]=1
    l=perm([],list(range(2,n+1)))
    c=0
    for s in l:
        s=[1]+s
        f=1
        for i in range(n-1):
            if gm[s[i]-1][s[i+1]-1]==0:
                f=0
                break
        if f:
            c+=1
    print(c)

if __name__=='__main__':
    main()
