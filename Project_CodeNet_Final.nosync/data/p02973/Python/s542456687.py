#!/usr/bin/env python

import sys

def DBsearch(L,x,narrow):
    n= len(L)
    if n==0: return 0
    if narrow and x in L: return L.index(x)
    last = L[-1]
    if x<last: return n
    if not narrow and x==last: return n
    #
    idx= -1
    i= 0
    j= n-1
    while j>=i:
        if i==j:
            if x>L[i]: idx= i
            break
        #
        mid= i + (j-i)//2
        if x<L[mid]:
            i= mid+1
        elif x==L[mid]:
            if narrow:
                idx= mid
                j  = mid - 1
            else:
                i = mid + 1
        else:
            idx= mid
            j= mid-1
    #
    return idx
#
def lds(L,narrow):
    seq= []
    for x in L:
        if len(seq)==0 or x<seq[-1]:
            seq.append(x)
        elif x==seq[-1]:
            if narrow:
                seq[DBsearch(seq,x,narrow)]= x
            else:
                seq.append(x)
        else:
            seq[DBsearch(seq,x,narrow)]= x
    #
    return len(seq)
#
n= int(sys.stdin.readline())
ai= [ int(sys.stdin.readline()) for _ in range(n) ]
print( lds( ai,False ) )
