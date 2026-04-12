def gya(n):
    return pow(n,pr-2,pr)
N=int(input())
A=list(map(int,input().split()))
pr=10**9+7
t=0
m=0
for i in A:
    t=(t+i)%pr
    m=(m+i**2)%pr
print(((t**2-m)*gya(2))%pr)