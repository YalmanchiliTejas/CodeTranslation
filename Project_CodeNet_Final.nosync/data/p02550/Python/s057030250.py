N,X,M=map(int,input().split())

if N==1 or M==1:
    print(X)
    exit()

F=(N-1).bit_length()

A=[[0]*M for _ in range(F)]

for x in range(M):
    A[0][x]=(x*x)%M

for d in range(1,F):
    for x in range(M):
        A[d][x]=A[d-1][A[d-1][x]]

S=[[0]*M for _ in range(F)]
for x in range(M):
    S[0][x]=A[0][x]

for d in range(1,F):
    for x in range(M):
        S[d][x]=S[d-1][x]+S[d-1][A[d-1][x]]

Ans=0
depth=0
N-=1
Y=X
while N>0:
    if N%2:
        Ans+=S[depth][X]
        X=A[depth][X]
    depth+=1
    N>>=1
print(Ans+Y)