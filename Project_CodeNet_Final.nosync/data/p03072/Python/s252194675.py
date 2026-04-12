n = int(input()) 
t = [int(i) for i in input().split()] 
ans = 0

for j in range(n):
  if t[0] <= t[j]:
    ans += 1
    t[0] = t[j]
print(ans)