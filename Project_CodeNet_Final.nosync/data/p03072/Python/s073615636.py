n = int(input())
H = list(map(int, input().split()))

ans = 1
base_h = H[0]

for i in range(1, n):
  if H[i]>=base_h:
    ans += 1
    base_h = H[i]
    
print(ans)