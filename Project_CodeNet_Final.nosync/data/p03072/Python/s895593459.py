n = int(input())
inns = list(map(int, input().split()))
res = []

for k, v in enumerate(inns):
  res.append(all(list(map(lambda x: x <= v, inns[:k + 1]))))

print(res.count(True))