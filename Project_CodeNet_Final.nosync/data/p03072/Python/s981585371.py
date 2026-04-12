a = int(input())
l = list(map(int, input().split()))
min = 0
cnt = 0
for i in range(a):
  if min <= l[i]:
    cnt += 1
    min = l[i]
print(cnt)
