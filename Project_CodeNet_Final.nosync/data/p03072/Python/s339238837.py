n = int(input())

a = list(map(int, input().split()))

min = 0
cnt = 0

for i in a:
  if min <= i:
    min = i
    cnt += 1

print(cnt)