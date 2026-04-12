N = int(input())
H = [int(i) for i in input().split()]
max_left = [0 for i in range(N)]
for i in range(1,N):
  max_left[i] = max(max_left[i-1], H[i-1])
res = 0
for i in range(N):
  if H[i] >= max_left[i]:
    res += 1
print (res)