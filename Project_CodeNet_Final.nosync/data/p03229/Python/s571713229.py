N=int(input())
A=[]
for i in range(N):A.append(int(input()))
A=sorted(A)
B=[0]*N
if N%2==0:
    for i in range(N):
        if i==N//2-1:
            B[0]=A[i]
        elif i<N//2-1:
            B[i*2+2]=A[i]
        else:
            B[-(i-N//2)*2-1]=A[i]
else:
    for i in range(N):
        if i==N//2:
            B[0]=A[i]
        elif i<N//2:
            B[i*2+2]=A[i]
        else:
            B[-(i-N//2)*2]=A[i]
r=0
for i in range(1,N):
    r += abs(B[i-1]-B[i])
A=A[::-1]
B=[0]*N
if N%2==0:
    for i in range(N):
        if i==N//2-1:
            B[0]=A[i]
        elif i<N//2-1:
            B[i*2+2]=A[i]
        else:
            B[-(i-N//2)*2-1]=A[i]
else:
    for i in range(N):
        if i==N//2:
            B[0]=A[i]
        elif i<N//2:
            B[i*2+2]=A[i]
        else:
            B[-(i-N//2)*2]=A[i]
s=0
for i in range(1,N):
    s += abs(B[i-1]-B[i])
print(max(r,s))