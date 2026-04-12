N = int(input())
H = list(map(int,input().split()))

obstacle = []
obstacle.append(H[0])

ans = 1
for i in range(1,N):
  for j in obstacle:
    if j > H[i]:
      obstacle.append(H[i])
      break
  else:
    obstacle.append(H[i])
    ans += 1
    
print(ans)