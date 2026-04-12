from collections import Counter
n = int(input())
l = list(Counter(input()) for i in range(n))
k =[]
m = 50
for i in l[0]:
  for t in l:
    m = min(m,t[i])
  k.append(i*m)
  m = 50
k.sort()
print("".join(k))