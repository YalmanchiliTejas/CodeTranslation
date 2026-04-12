N = input()
Hs = input().strip().split(' ')
ans = 0;
H = 0;
for i in Hs:
  i = int(i)
  if (i >= H):
  	ans += 1
  H = max(H, i)

print(ans)