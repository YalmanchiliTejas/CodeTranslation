N=int(input())
A=list(map(int,input().split()))
b=0
c=0

for j in range(0,len(A)):
    c+=A[j]

for i in range(0,len(A)):
        c=c-A[i]
        b+=A[i]*c
        
print(b%(10**9+7))