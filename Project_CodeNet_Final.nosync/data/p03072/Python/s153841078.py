n = int(input())
h = list(map(int, input().split()))

count = 0

for num, hight in enumerate(h):
  if hight >= max(h[:num+1]):
    count += 1

print(count)