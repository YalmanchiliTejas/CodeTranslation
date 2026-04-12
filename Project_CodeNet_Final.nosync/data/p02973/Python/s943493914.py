import bisect
m = int(input())
a = []
for _ in range(m):
  a.append(int(input()))

a = list(map(lambda x: -x, a))
m = len(a)

lis = [float('inf')]*m

for x in a:
  lis[bisect.bisect_right(lis, x)] = x

print(len([x for x in lis if not (x == float('inf'))]))