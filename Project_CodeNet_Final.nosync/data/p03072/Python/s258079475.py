count = 0

n = int(input())
h = list(map(int, input().split()))

for i in range(n):
  h_short = h[:i+1] 
  if h[i] >= max(h_short):
    count += 1
  
print(count)