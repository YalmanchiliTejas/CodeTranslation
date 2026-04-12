n=int(input())
a=input()
if n!=1:
  b=input()
  m=[]
  if len(a)>len(b):
    a,b=b,a
  b=list(b)
  for i in a:
    for j in range(len(b)):
      if i==b[j]:
        m.append(i)
        b[j]=''
        break
  for _ in range(n-2):
    s=list(input())
    l=[]
    for i in m:
      for j in range(len(s)):
        if i==s[j]:
          l.append(i)
          s[j]=''
          break
    m=l
  print(''.join(sorted(m)))  
else:
  print(''.join(sorted(a)))