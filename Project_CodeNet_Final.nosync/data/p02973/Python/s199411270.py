from bisect import bisect_right
n = int(input())
a = int(input())
x = [a * (-1)]
for _ in range(n-1):
  a = int(input()) * (-1)
  if a >= x[-1]:
    x.append(a)
  else:
    index = bisect_right(x, a)
    x[index] = a
print(len(x))
