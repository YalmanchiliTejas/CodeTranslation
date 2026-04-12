import collections
n=int(input())
f={}
for i in range(n):
  S=input() 
  s=list(S)
  c=collections.Counter(S)
  for j in range(len(c)):
    x=c.most_common()[j][0]
    y=c.most_common()[j][1]
    if i==0:
      f.setdefault(x,y)
    else:
      for k in f.keys():
        if k not in s:
          f[k]=0
        else:
          if f[k]>s.count(k):
            f[k]=s.count(k)
A=sorted(f)
li=[a*f[a] for a in A]
print("".join(li))