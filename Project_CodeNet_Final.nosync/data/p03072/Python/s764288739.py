N = int(input())
i = 0
max = 0
cnt = 0
for x in input().split():
  x = int(x)
  if x >= max:
    cnt = cnt + 1
    max = x

print(cnt)