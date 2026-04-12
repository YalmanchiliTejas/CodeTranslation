h,w=map(int,input().split())
l=[list(input()) for i in range(h)]

l=[i for i in l if '#' in i]
l=[list(i) for i in zip(*l)]
l=[i for i in l if '#' in i]
l=[list(i) for i in zip(*l)]

for i in l:
  print(''.join(i))