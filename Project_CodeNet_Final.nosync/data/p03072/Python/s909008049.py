n = int(input())
l = list(map(int, input().split()))
c = 1

bean = True
for i in range(1, n):
  bean = True
  for j in range(i, 0, -1):
    if l[j-1] > l[i]:
      bean = False
  if bean:
    c += 1

print(c)


