N=int(input())
A=sorted([int(input()) for i in range(N)])
#A=[i for i in range(50)]
#N=len(A)
value=0
B,C=A[0],A[0]
i=1
z=0

while N-1>z:

    if z%4==0:
        value+=A[-i]-B
        B=A[-i]
    if z%4==1:
        value+=A[-i-1]-C
        C=A[-i-1]
    if z%4==2:
        value+=B-A[i]
        B=A[i]
    if z%4==3:
        value+=C-A[i+1]
        C=A[i+1]
        i+=2
    #print(B,C,i,z)
    z+=1
value1=value
value=0
B,C=A[-1],A[-1]
i=0
z=0
while N-1>z:

    if z%4==0:
        value+=B-A[i]
        B=A[i]

    if z%4==1:
        value+=C-A[i+1]
        C=A[i+1]

    if z%4==2:
        value+=A[-i-2]-B
        B=A[-i-2]
    if z%4==3:
        value+=A[-i-3]-C
        C=A[-i-3]
        i+=2
    #print(B,C,i,z,value)
    z+=1
value2=value
print(max(value1,value2))
