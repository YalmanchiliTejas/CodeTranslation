N = int(input())
H = list(int(i) for i in (input().split()))
H_max = []
tmp = 0
cnt = 0
for i in range (N):
  if (tmp < H[i]):
    H_max.append(H[i])
    tmp = H[i]
  else:
    H_max.append(tmp)
  if(H[i] >= H_max[i]):
    cnt += 1
print(cnt)