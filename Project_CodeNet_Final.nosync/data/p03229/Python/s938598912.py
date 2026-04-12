N=int(input())

A=[int(input()) for i in range(N)]

A.sort()

ansl=A[0]
ansr=A[-1]
l=1
r=-2
n=[0]*4
ansn=abs(A[0]-A[-1])
for i in range(N-2):
    n[0]=abs(A[l]-ansl)
    n[1]=abs(A[l]-ansr)
    n[2]=abs(A[r]-ansl)
    n[3]=abs(A[r]-ansr)
    if n[0]==max(n):
        ansn+=n[0]
        ansl=A[l]
        l+=1
    elif n[1]==max(n):
        ansn+=n[1]
        ansr=A[l]
        l+=1
    elif n[2]==max(n):
        ansn+=n[2]
        ansl=A[r]
        r-=1
    elif n[3]==max(n):
        ansn+=n[3]
        ansr=A[r]
        r-=1

print(ansn)