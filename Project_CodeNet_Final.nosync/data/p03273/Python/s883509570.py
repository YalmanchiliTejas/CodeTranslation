h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
a=[x for x in a if "#" in x]
a=[x for x in zip(*a) if "#" in x]
a=[list(x) for x in zip(*a)]
for b in a:
  print("".join(b))