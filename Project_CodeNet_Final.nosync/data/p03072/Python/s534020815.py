it = int(input())
lists = list(map(int,input().split()))
x = 0
i = it 

for j in range(i):
  listo = lists[:j+1]
  if max(listo) == lists[j]:
    x += 1
  else:
    continue

print(x)