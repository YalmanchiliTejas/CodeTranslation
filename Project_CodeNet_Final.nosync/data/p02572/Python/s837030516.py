n=int(input())
l=list(map(int,input().split()))
s=0
m=1000000007
s1=sum(l)
s1=(s1*s1)
s2=0
for i in range(n):
  s2=s2+l[i]*l[i]
print(((s1-s2)//2)%m)
  