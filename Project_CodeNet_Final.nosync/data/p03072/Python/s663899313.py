n = int(input())
h = list(map(int, input().split()))

result = 1
h_high = h[0]

for i in range(1, n):
  if h_high <= h[i]:
    result += 1
    h_high = h[i]
    
print(result)
