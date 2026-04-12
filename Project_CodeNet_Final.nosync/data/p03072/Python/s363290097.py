input()
lst = list(map(int, input().split()))

cnt = 0
previous = 0
for i in range(len(lst)):
  if previous <= lst[i]:
    cnt += 1
    previous = lst[i]
print(cnt)