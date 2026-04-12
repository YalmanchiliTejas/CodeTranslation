N=int(input())
A =list(map(int,input().split()))
S =(sum(A))**2
for i in A:
        S-=i**2
a =10**9+7
print((S//2)%a)