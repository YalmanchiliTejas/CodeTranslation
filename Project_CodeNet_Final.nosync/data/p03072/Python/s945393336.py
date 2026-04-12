N = int(input())
H = list(map(int,input().split()))
a = H[0]
b = 0
for i in range(N):
  if a <= H[i]:
    a = H[i]
    b += 1
print(b)
