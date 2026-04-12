h, w = map(int, input().split())
cnt = 0
for _ in range(h):
  cnt += input().count('#')

if cnt == h + w - 1:
  ans = 'Possible'
else:
  ans = 'Impossible'
print(ans)