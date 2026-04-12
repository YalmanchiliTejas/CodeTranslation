#!/usr/bin/env python
while 1:
    T,U,N,E,W,S=1,6,5,3,4,2
    n=int(raw_input())
    if n==0: break
    ans=T
    for i in range(n):
        di=raw_input()
        if di=="North":
            N,T,S,U=T,S,U,N
        elif di=="East":
            E,U,W,T=T,E,U,W
        elif di=="South":
            T,S,U,N=N,T,S,U
        elif di=="West":
            T,E,U,W=E,U,W,T
        elif di=="Left":
            E,S,W,N=S,W,N,E
        elif di=="Right":
            S,W,N,E=E,S,W,N
        else:
            print '[*] Error ->',di
            raise IOError
        ans+=T
    print ans