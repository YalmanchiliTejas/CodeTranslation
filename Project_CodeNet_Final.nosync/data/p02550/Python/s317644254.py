import sys
N,X,M=map(int, sys.stdin.readline().split())

A=[]
A.append(X)
visit={}
for i in range(M+1):
    X=pow(X,2,M)
    if X not in visit:
        visit[X]=1
        A.append(X)
    else:
        break
loop_point=A.index(X)
notloop=A[:loop_point]
loop=A[loop_point:]

len_notloop=len(notloop)
len_loop=len(loop)


SUM_notloop=[0]
for x in notloop:
    SUM_notloop.append(SUM_notloop[-1]+x)


SUM_loop=[0]
for x in loop:
    SUM_loop.append(SUM_loop[-1]+x)

ans=0
if len_notloop<N:
    ans+=SUM_notloop[-1]
    N-=len_notloop
    sho,amari=N/len_loop,N%len_loop
    ans+=SUM_loop[-1]*sho
    ans+=SUM_loop[amari]
elif N<=len_notloop:
    ans=SUM_notloop[N]
print ans
