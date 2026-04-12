n = int(input())
hn = list(map(int, input().split(' ')))
cnt = 0
max_h = 0
for hi in hn:
  if max_h <= hi:
    cnt += 1
  max_h = max(max_h, hi)
print(cnt)