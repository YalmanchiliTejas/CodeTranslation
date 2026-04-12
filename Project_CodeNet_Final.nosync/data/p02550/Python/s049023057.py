n,x,m=map(int,input().split())
s=set()
p=[]
while x not in s:
  s.add(x)
  p+=[x]
  x=(x*x)%m
  if len(p)>=n:print(sum(p));quit()
r=b=t=v=0
a=[0]
for i in p:
  if i==x:b=1
  r+=1-b
  t+=b*i
  v+=i
  a+=[a[-1]+i]*b
l=len(p)
print(v+t*((n-l)//(l-r))+a[(n-l)%(l-r)])