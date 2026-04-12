n = int(input())
a = list(map(int, input().split()))
maxIndex = [i for i, x in enumerate(a) if x == max(a)]
c = a[:maxIndex[-1]+1]
max = c[0]
r = len(c)
cnt = 0
for t in c:
  if max <  t:
    max = t
  if max > t:
    cnt += 1
print(r - cnt)