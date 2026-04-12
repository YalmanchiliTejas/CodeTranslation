n=int(input())
#t=list(input())
#t.sort()
abc='abcdefghijklmnopqrstuvwxyz'
c=0
y=''
a=[0 for i in range(len(abc))]
'''
for i in range(len(abc)):
  a[i]=t.count(abc[i])
print(a,t)
'''
s=['' for i in range(n)]
for i in range(n):
  s[i]=input()

ans=''
for x in abc:
  z=100
  v=100
  for w in s:
    z=w.count(x)
    v=min(z,v)
  ans+=x*v
    
print(ans)