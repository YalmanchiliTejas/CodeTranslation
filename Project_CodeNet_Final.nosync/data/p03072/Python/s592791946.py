N = int(input())
H_ = list(map(int,input().split()))
count = 0
H_ = H_[::-1]
for i in range(N):
  flg = 0
  for j in range(i,N):
    if H_[i] < H_[j]:
      flg = 1
  if flg == 0:
    count += 1
print(count)