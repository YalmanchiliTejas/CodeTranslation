r,g,b=map(int,raw_input().split())
a=100*r+10*g+b
if a%4==0:print 'YES'
else:print 'NO'