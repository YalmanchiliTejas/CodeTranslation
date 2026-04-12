n = int(input())
h = list(map(int,input().split()))
m = 1

for i in range(1,n):
  tmp = 0
  for j in range(i):
    if(h[i] < h[j]):
      tmp += 1
  if(tmp == 0):
    m += 1
print(m)