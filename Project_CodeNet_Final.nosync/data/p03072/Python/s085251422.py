h = int(input())
mount = [int(_) for _ in input().split()]
count = 0
for i in range(h):
  if i == 0:
    count += 1
  else:
    for j in range(i):
      if mount[i]<mount[j]:
        break
    else:
      count += 1
print (count)