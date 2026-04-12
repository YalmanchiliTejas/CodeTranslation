N = int(input())
H = list(map(int,input().split(' ')))

res = H[0]
num = 0
for i in range(N):
  if res <= H[i]:
    num += 1
    res = H[i]
  else:
    pass
print(num)