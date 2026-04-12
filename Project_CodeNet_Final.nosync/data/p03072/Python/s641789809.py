n = int(input())
H = [int(i) for i in list(input().split())]
tmp = 0
ans = 0
for i in range(n):
  if tmp <= H[i]:
    tmp = H[i]
    ans += 1
print(ans)