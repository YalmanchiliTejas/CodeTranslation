n = int(input())
min_counts = [100] * 26
for _ in range(n):
  s = input()
  counts = [0] * 26
  for c in s:
    i = ord(c) - ord('a')
    counts[i] += 1
  for i in range(26):
    min_counts[i] = min(min_counts[i], counts[i])
#print(min_counts)
ans = []
for i in range(26):
  c = chr(ord('a') + i)
  ans.append(c * min_counts[i])
print(''.join(ans))
  