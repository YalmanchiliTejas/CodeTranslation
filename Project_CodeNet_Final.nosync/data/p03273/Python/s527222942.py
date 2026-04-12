h,w=map(int,input().split())
p=[1 for x in range(w)]
l=list()

for i in range(h):
  s=input()
  if '#' in s:
    l.append(s)
    for j in range(w):
      p[j] *= 1 if s[j]=='.' else 0

for i in range(len(l)):
  for j in range(w):
    if p[j]==0:
      print(l[i][j],end='')
  print()
