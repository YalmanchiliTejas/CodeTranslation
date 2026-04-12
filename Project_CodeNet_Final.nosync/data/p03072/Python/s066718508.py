n = int(input())
h = list(map(int, input().split()))

mh = h[0]
cv = 1

for i in range(1, n):
  if h[i] >= mh:
    mh = h[i]
    cv += 1
    
print(cv)