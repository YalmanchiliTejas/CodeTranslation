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
a1 = sum(A)%p
B = [A[i]**2 for i in range(N)]
a2 = 0
for i in range(N):
    a2 = (a2+B[i])%p
ans = (((a1*a1)%p-a2)%p * pow(2,p-2))%p
print(ans)