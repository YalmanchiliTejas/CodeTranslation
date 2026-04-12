n = int(input())
a=list(map(int, input().split()))
count = 0
m = 0
for e in a:
  if e >= m:
    count += 1
    m = e
print(count)