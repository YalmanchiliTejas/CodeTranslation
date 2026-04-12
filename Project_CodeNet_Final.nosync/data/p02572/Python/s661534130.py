n=int(input())
a=list(map(int,input().split()))
s=0
v=0
for i in range(n):
    s+=a[i]
    v+=a[i]**2
s_2=s**2
print(((s_2-v)//2)%(10**9+7))