#abc095c

a,b,c,x,y=map(int,raw_input().split())
res=float('inf')
for i in xrange(100000+2):
 t=2*c*i+max(0,x-i)*a+max(0,y-i)*b
 res=min(res,t)
print res
