# f=open('in','r')
# input=lambda:f.readline().strip()

n=int(input())
r=list(map(int,input().split()))
mod=1000000007
s=sum(r)%mod
x=0
for u in r:
  x+=u**2
x%=mod
t=500000004
print((s**2-x)*t%mod)