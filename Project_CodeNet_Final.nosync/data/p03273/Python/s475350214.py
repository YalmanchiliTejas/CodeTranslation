h,w=map(int,input().split())
s=[]
l=set()
for i in range(h):
  a=list(input())
  if set(a) != set("."):
    s.append(a)
    for j in range(w):
      if a[j]=="#":
        l|={j}
for i in s:
  p=""
  for j in sorted(list(l)):
    p+=i[j]
  print(p)
