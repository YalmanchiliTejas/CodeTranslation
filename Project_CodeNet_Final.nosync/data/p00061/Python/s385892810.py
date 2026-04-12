import sys
d={}
while 1:
  a,b=map(int,raw_input().split(","))
  if a==b==0: break
  d[a]=b

x=sorted(set(d.values()))[::-1]
for s in sys.stdin:
  print x.index(d[int(s)])+1