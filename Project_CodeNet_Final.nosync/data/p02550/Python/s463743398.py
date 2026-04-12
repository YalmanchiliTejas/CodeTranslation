#E
N,X,M=map(int,input().split())

F=[0 for i in range(10**5+1)]
for i in range(10**5+1):
    F[i]=pow(i,2,M)
    
Flag=[False for i in range(10**5+1)]
A_i=X
while True:
    A_i=F[A_i]
    if Flag[A_i]:
        st=A_i
        break
    Flag[A_i]=True

A_i=X
Sum_1=0
cnt=0
while True:
    if A_i==st:
        break
    cnt+=1
    Sum_1+=A_i
    A_i=F[A_i]

roop=1
A_i=st
Sum_2=0
while True:
    Sum_2+=A_i
    A_i=F[A_i]
    if A_i==st:
        break
    roop+=1

    
A_i=st
Sum_3=0
for i in range((N-cnt)%roop):
    Sum_3+=A_i
    A_i=F[A_i]
    
    
if N-cnt>roop:
    ans=Sum_1+Sum_2*((N-cnt)//roop)+Sum_3
elif N<=cnt:
    ans=0
    A_i=X
    for i in range(N):
        ans+=A_i
        A_i=F[A_i]

else:
    ans=Sum_1
    A_i=st
    for i in range(N-cnt):
        ans+=A_i
        A_i=F[A_i]

print(ans)