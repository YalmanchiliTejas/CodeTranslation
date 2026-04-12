n = int(input())
a = map(int, input().split())
mx = 0
cnt = 0
for i in a:
  if i >= mx:
    cnt += 1
    mx = i
print(cnt)