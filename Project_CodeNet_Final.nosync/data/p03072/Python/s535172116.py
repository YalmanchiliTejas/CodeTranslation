N = int(input())
H = [int(i) for i in input().split()] 
hight = 0
res = 0

for i in range(N):
  if hight <= H[i]:
    hight = H[i]
    res += 1
print(res)

