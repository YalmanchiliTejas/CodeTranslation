n = int(input())
a = list(map(int, input().split()))

res = 0
for indexa, valuea in enumerate(a):
  for indexb, valueb in enumerate(a):
    if valuea < valueb and indexa != indexb:
      break
    if indexa == indexb:
      res += 1

print(res)