H, W = map(int, input().split())
b = 0
ans = 'Possible'
for i in range(H):
  a = input()
  for j in range(W):
    if a[j] == '#':
      if j>=b:
        b = j
      else:
        ans = 'Impossible'
print(ans)
      