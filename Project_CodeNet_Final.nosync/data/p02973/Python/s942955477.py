# ABC134E

import sys
input=sys.stdin.readline

def bisectR(ite,x):
    st=-1
    en=len(ite)
    while(en-st>1):
        mid=(en+st)//2
        if ite[mid]<x:
            en=mid
        else:
            st=mid
    return en

def main():
    N=int(input())
    A=[int(input()) for i in range(N)]
    
    lbds=[A[0]]
    for i in range(1,N):
        if lbds[-1]>=A[i]:
            lbds+=[A[i]]
        else:
            x=bisectR(lbds,A[i])
            lbds[x]=A[i]
    print(len(lbds))
    
if __name__=="__main__":
    main()
