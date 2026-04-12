n=input()
a=input().split()
sum=0
for i in range(len(a)):
  a[i]=(int)(a[i])
for i in a:
  sum+=i
ans=0
ans+=(sum**2)
for i in a:
  ans-=i*i
print((ans//2)%(10**9+7))