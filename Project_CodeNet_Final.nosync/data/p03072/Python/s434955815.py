N = int(input())
H = list(map(int, input().split()))
x = H[0]
y = 0
for i in range(N):
  if x <= H[i]:
    x = H[i]
    y += 1
print(y)