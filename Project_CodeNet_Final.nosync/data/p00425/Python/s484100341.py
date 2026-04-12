import sys
e=sys.stdin.readline
p={'N':(1,5,2,3,0,4),'E':(3,1,0,5,4,2),'W':(2,1,5,0,4,3),
   'S':(4,0,2,3,5,1),'R':(0,2,4,1,3,5),'L':(0,3,1,4,2,5)}
for n in iter(e,'0\n'):
 a=1;s=[1,2,3,4,5,6]
 for _ in[0]*int(n):
  s=[s[i]for i in p[e()[0]]]
  a+=s[0]
 print(a)
