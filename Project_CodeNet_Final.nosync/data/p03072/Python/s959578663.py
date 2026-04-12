#abc124b

n=int(raw_input())
h=map(int,raw_input().split())
mh=h[0]
cnt=1
for i in xrange(1,n):
 if h[i]>=mh:
  mh=h[i]
  cnt+=1
print cnt
