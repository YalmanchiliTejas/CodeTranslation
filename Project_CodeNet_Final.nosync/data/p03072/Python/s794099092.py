N = int(input())
H = list(map(int, input().split()))
ans = 0

for i in range(N):
  if i == 0:
    ans += 1
  else:
    h = H[i]
    tmp = True
    
    for j in range(i-1, -1, -1):
      # print(i, j, h)
      tmp = tmp and h >= H[j]
    
    if tmp:
	    ans += 1

print(ans)