n = int(input())
h = list(map(int,input().split()))
M = 0
count = 0
for i in range(n):
  if M <= h[i]:
    count += 1
    M = h[i]
print(count)