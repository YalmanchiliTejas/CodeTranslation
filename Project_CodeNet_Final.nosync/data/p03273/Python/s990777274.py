h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
s=[]
for i in a:
  if(i.count("#")!=0):s.append(i)
a = [list(x) for x in zip(*s)]
s=[]
for i in a:
  if(i.count("#")!=0):s.append(i)
a = [list(x) for x in zip(*s)]
for i in a:print("".join(i))