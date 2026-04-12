def f(l,x):
  z=[]
  for i in range(x):
    if set(l[i])!=set('.'):
      z.append(l[i])
  return list(map(list, zip(*z)))
h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
l=f(f(a,h),w)
for i in range(len(l)):
  print(''.join(l[i]))