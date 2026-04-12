N = int(input())

H = list(map(int, input().split()))

ans = 0

for i in range(N):
  if i == 0:
    ans += 1
  else:
    h = H[:i+1]
    if max(h) == H[i]:
      ans += 1
 
print(ans)
