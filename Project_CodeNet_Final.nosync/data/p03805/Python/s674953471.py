import itertools
n, m = list(map(int, input().split()))
a = [list(map(int, input().split())) for _ in range(m)]
y = 0
s = []
for i in range(1, n):
  s.append(i+1)
for x in itertools.permutations(s):
  if [1, int(x[0])] in a:
      for i in range(n-2):
          if not [int(x[i]), int(x[i+1])] in a and not [int(x[i+1]), int(x[i])] in a:
            break
      else: y += 1
print(y)