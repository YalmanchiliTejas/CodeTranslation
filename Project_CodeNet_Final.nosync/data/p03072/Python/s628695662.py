N = int(input())
H =list(map(int, input().split()))

count = 0
max1 = 0

for i in range(N):
  max1 = max(max1, H[i])
  if H[i] == max1:
    count += 1
  
print(count)