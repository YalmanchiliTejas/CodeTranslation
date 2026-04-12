n = int(input())
H = list(map(int, input().split()))

ans = 1
for i in range(0,n-1):
  if max(H[0:i+1]) <= H[i+1]:
    ans += 1
    
print(ans)
