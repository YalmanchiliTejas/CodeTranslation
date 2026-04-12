n=int(input())
l=list(map(int,input().split()))
an=0;md=10**9+7
suf=[0]*n
suf[-1]=l[-1]
for i in range(n-2,-1,-1):
  suf[i]=suf[i+1]+l[i]
for i in range(n-1):
  an=(an+l[i]*suf[i+1])%md
print(an)