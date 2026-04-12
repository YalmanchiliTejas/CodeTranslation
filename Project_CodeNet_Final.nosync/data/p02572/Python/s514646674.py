n=int(input())
a=list(map(int,input().split()))
ss=sum(a)
s=0
for i in range(len(a)):
    ss=ss-a[i]
    s+=a[i]*ss
print(s%(10**9+7))