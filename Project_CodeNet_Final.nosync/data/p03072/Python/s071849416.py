N = int(input())
H = list(map(int, input().split()))

count = 0
max_H = H[0]

for i in range(N):
  if H[i]>=max_H:
    count+=1
  max_H = max(max_H, H[i])
print(count)