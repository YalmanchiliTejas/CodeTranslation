n=int(input())
def multiset(a,b): #listのab
  x,y=list(set(a)&set(b)),[]
  for s in x:
    for t in range(min([a.count(s),b.count(s)])):
      y.append(s)
  return y
for s in range(n):
  a=list(input())
  if s==0:
    b=a
  b=multiset(a,b)
print("".join(sorted(b)))