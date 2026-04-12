n = input()
memo = [[0] * n for _ in range(26)]
for i in range(n):
  for c in raw_input():
    memo[ord(c) - ord('a')][i] += 1
res = ''
for i, count_per_char in enumerate(memo):
  res += chr(ord('a') + i) * min(count_per_char)
print res