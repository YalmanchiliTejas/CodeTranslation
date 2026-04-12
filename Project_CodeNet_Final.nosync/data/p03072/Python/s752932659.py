N = int(input())
H = list(map(int,input().strip().split(" ")))
maxH = H[0]
look = 1
for i in range(N-1):
  if H[i+1] >= maxH:
    look = look + 1
    maxH = H[i+1]
print(look)
