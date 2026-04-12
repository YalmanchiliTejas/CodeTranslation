n = int(input())
mountains = list(map(int, input().split()))

good = 0
for i in range(n):
  if i == 0:
    good += 1
  else:
    left = max(mountains[0:i])
    if left <= mountains[i]:
      good += 1
print(good)