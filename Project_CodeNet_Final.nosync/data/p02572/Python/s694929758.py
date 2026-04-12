def pow(x,m):
    if m==0:
        return 1
    if m==1:
        return x
    if m%2==0:
        return (pow(x,m//2)**2)%p
    else:
        return (x*(pow(x,(m-1)//2)**2)%p)%p
p = 10**9+7
N = int(input())
A = list(map(int,input().split()))
a = sum(A)
b = 0
for i in range(N):
    b = (b+A[i]**2)%p
ans = (a*a)%p-b
ans = (pow(2,p-2)*ans)%p
print(ans)