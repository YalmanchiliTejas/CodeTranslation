import bisect
n = int(input())
a = [int(input()) for i in range(n)]
c = [a[-1]]
for i in a[n-2::-1]:
  if c[-1] <= i:
    c.append(i)
  else:
    c[bisect.bisect_left(c,i+1)] = i
  #print(c)
print(len(c))