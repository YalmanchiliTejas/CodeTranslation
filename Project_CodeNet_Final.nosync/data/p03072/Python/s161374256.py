re = 1
N = int(input())
H = list(map(int, input().split()))
tmp = H[0]

for i in range(1, N):
  if tmp <= H[i]:
    re += 1
    tmp = H[i]
    
print(re)