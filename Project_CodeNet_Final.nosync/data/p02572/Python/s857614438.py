mod=10**9+7
n=int(input())
a=list(map(int,input().split()))
s=a[-1]
c=0
for i in range (n-2,-1,-1):
    c+=a[i]*s
    c%=mod
    s+=a[i]
print(c)