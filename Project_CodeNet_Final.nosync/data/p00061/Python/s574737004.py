import sys
c,d=[],{}
for x in iter(input,'0,0'):
 p,s=map(int,x.split(','))
 c+=[s]
 d[p]=s
for y in sys.stdin:print(sorted({*c})[::-1].index(d[int(y)])+1)
