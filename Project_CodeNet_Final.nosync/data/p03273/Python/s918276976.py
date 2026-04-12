h,w=map(int,input().split())
T=[list(input()) for i in range(h)]
while ["."]*w in T:
  T.remove(["."]*w)
  h-=1
T=list(list(i) for i in zip(*T))
while ["."]*h in T:
  T.remove(["."]*h)
T=list(list(i) for i in zip(*T))
for t in T:
  print("".join(t))