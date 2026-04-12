n = int(input())
H = list(map(int,input().split()))
c = 0
maxh = 0
for i in range(n):
  if maxh <= H[i]:
    c += 1
    maxh = H[i]
print(c)