N = int(input())
H = list(map(int,input().split()))
h = H[0]
count = 1
for i in range(N-1):
  if h <= H[i+1]:
    h = H[i+1]
    count += 1
print(count)