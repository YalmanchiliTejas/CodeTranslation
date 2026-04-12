n=int(input());a=list(map(int,input().split()))
s=[]
l=0
for e in a:
  if len(s)>0:
    if all([e>=c for c in s]):
      l+=1
  s.append(e)
print(l+1)