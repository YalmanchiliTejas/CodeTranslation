N = int(input())
A = list(map(int, input().split()))
c=0
d=sum(A)
for i in range(0,N-1):
    d-=A[i]
    c+=A[i]*d
    if(c>10**9+7):
        c%=(10**9+7)
print(c)

