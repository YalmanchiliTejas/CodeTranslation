h,w=map(int, input().split())
l=[list(input()) for i in range(h)]

for i in reversed(range(h)):
  if all(j=="." for j in l[i]):
    l.pop(i)
for i in reversed(range(w)):
  if all(j[i]=="." for j in l):
    for j in l:
      j.pop(i)
for i in l:
  print(''.join(i))
  