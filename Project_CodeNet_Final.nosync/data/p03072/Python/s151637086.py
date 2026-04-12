N = int(input())
H = list(map(int, input().split()))

max_h = H[0]
count = 1
for i in range(1, N, 1):
  if H[i] >= max_h:
    count += 1
    max_h = H[i]
print(count)