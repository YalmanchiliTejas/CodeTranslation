d = [chr(i) for i in range(ord('a'), ord('z') + 1)]
ans = [10 ** 9] * 26
n = int(input())
for i in range(n):
  s = input()
  for j in range(26):
    ans[j] = min(ans[j], s.count(d[j]))
for i in range(26):
  print(d[i] * ans[i], end='')
print('')
