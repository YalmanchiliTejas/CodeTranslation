n=input()
lst=list(map(int,input().split()))
m=sum(lst)%(10**9+7)
s=0
for i in lst:
    s=(s+i*i)%(10**9+7)
a=(m*m-s)%(10**9+7)
if a%2:print(a//2+5*10**8+4)
else:print(a//2)