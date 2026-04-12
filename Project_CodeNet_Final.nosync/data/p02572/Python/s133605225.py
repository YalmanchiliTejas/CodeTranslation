p = 10**9+7
def pow(x,m):
    if m==0:
        return 1
    if m==1:
        return x
    if m%2==0:
        return (pow(x,m//2)**2)%p
    else:
        return (x*(pow(x,(m-1)//2)**2)%p)%p
N = int(input())
A = list(map(int,input().split()))
a0 = ((sum(A)%p)*(sum(A)%p))%p
a1 = 0
for i in range(N):
    a1 = (a1+A[i]**2)%p
a = a0-a1
a = (pow(2,p-2)*a)%p
print(a)