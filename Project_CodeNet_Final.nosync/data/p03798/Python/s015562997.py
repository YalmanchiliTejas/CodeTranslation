N=int(input())
S=input()
L1,L2,L3,L4='SS','SW','WS','WW'

def make_seq(L):
    for i in range(1,N-1):
        if S[i]+L[i-1]+L[i] in ['oSS','oWW','xSW','xWS']:
            L+='S'
        else:
            L+='W'
    return L

T=['oSSS','oWSW','oSWW','oWWS','xWSS','xSSW','xSWS','xWWW']
def check(L):
    if S[0]+L[-1]+L[0]+L[1] in T and S[-1]+L[-2]+L[-1]+L[0] in T:
        return L
    else:
        return -1

L1=make_seq(L1)
L2=make_seq(L2)
L3=make_seq(L3)
L4=make_seq(L4)
C=[check(L1),check(L2),check(L3),check(L4)]

import sys
for i in C:
    if i!=-1:
        print(i)
        sys.exit()
print(-1)