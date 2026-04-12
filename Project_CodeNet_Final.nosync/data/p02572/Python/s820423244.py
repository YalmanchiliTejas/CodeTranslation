N=int(input())
A = [int(x) for x in input().split()]
s=sum(A)
x=0
for i in range(N):
    s=s-A[i]
    x+=s*A[i]    
print(x%(10**9+7))
        
