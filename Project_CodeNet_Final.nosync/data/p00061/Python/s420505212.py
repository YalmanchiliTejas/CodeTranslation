import sys
li=[0]*101
sc=[False]*31
ra=[0]*31
while True:
    (n,s)=map(int,raw_input().split(","))
    if (n,s)==(0,0):break
    sc[s]=True
    li[n]=s
r=1
for i in xrange(30,-1,-1):
    if sc[i]:
        ra[i]=r
        r+=1
for line in sys.stdin.readlines():
    print ra[li[int(line.strip())]]