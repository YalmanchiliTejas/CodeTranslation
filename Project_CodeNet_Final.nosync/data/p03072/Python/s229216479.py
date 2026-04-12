N = int(input())
H = list(map(int, input().split()))
Ma = H[0]
count = 0
for i in range(N):
  if Ma <= H[i]:
    count += 1
    Ma = H[i]
print(count)