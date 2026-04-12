n = int(input())
h = list(map(int, input().split()))
m = 1
for i in range(1,n):
  if max(h[:i]) <=h[i]:
    m += 1
print(m)