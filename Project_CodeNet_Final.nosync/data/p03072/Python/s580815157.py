n = int(input())
h = [int(i) for i in input().split()]
cnt = 1
max = h[0]
for i in range(1, len(h)):
  if(max <= h[i]):
    cnt+= 1
    max = h[i]
  else:
    cnt += 0
print(cnt)