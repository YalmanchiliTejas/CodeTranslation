N = int(input())
H = list(map(int, input().split()))

ans = 1
for i in range(0, N):
  for j in range(0, i):
    if H[j] > H[i]:
      break
    if  j + 1 == i:
      ans += 1
    
print (ans)