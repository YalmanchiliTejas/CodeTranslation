n = int(input())
h = list(map(int, input().split()))
ans = 1
tmp = h[0]
for i in range(1,n):
    if tmp <= h[i]:
          ans += 1
          tmp = h[i]
print(ans)