H,W=map(int,input().split())
tmp=[]

for i in range(H):
  l=input()
  if '#' in l:
    tmp.append(l)

ans=[]
for l in zip(*tmp):
  if '#' in l:
    ans.append(''.join(l))

for l in zip(*ans):
  print(''.join(l))