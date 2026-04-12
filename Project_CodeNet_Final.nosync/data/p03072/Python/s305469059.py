n = int(input())
info = list(map(int,input().split()))
first = info[0]
res = 1
for i in info[1:]:
  if i >= first:
    res += 1
    first = i
print(res)