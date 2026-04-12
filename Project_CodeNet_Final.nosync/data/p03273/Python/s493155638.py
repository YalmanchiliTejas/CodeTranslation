h,w=map(int,input().split())
s=[list(input())for i in range(h)]
l=[x for x in s if '#' in x]
ans=[]
for i in zip(*l):
  if '#' in i:ans.append(i)
an=zip(*ans)
for x in an:
  print(''.join(x))