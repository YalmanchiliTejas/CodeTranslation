N=int(input())
A=list(map(int,input().split()))
Mod=10**9+7
two_inverse=pow(2,Mod-2,Mod)

X=sum(A)%Mod

Y=0
for a in A:
    Y+=a*a
    Y%=Mod

print(((X*X-Y)*two_inverse)%Mod)
    
