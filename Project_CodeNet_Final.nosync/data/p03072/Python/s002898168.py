N = int(input())
H = list(int(i) for i in input().split())
count = 0
high = 0
for i in range(N):
  if H[i] >= high:
    count += 1
    high = max(high, H[i]) 
  else:
    high = max(high, H[i])
print(count)