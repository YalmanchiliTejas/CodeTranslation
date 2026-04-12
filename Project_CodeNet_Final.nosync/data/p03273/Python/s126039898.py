from sys import stdin
nii=lambda:map(int,stdin.readline().split())
lnii=lambda:list(map(int,stdin.readline().split()))

h,w=nii()
a=[list(input()) for i in range(h)]

t_ans=[]
for i in a:
  if '#' in i:
    t_ans.append(i)

t_ans=[i for i in zip(*t_ans)]

ans=[]
for i in t_ans:
  if '#' in i:
    ans.append(i)

ans=[i for i in zip(*ans)]

for i in ans:
  print(''.join(i))