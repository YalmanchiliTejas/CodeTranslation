#coding: UTF-8
import sys
N=int(input())
Say=input()
A1='SS'
A2='WS'
A3='SW'
A4='WW'
def Nextone(a,b,w):
    if w=='o':
        if a=='S' and b=='S':
            return 'S'
        elif a=='W' and b=='S':
            return 'W'
        elif a=='S' and b=='W':
            return 'W'
        else:
            return 'S'
    else:
        if a=='S' and b=='S':
            return 'W'
        elif a=='W' and b=='S':
            return 'S'
        elif a=='S' and b=='W':
            return 'S'
        else:
            return 'W'

for i in range(0,N):
    A1+=Nextone(A1[i],A1[i+1],Say[i])
    A2+=Nextone(A2[i],A2[i+1],Say[i])
    A3+=Nextone(A3[i],A3[i+1],Say[i])
    A4+=Nextone(A4[i],A4[i+1],Say[i])
if A1[1]==A1[N+1] and A1[0]==A1[N]:
    print(A1[1:N+1])
elif A2[1]==A2[N+1] and A2[0]==A2[N]:
    print(A2[1:N+1])
elif A3[1]==A3[N+1] and A3[0]==A3[N]:
    print(A3[1:N+1])
elif A4[1]==A4[N+1] and A4[0]==A4[N]:
    print(A4[1:N+1])
else:
    print(-1)