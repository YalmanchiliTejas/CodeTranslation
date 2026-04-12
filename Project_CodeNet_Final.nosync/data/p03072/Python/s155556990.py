n = int(raw_input())
m = map(int, raw_input().split())
max_m = [0 for i in range(n)]
max_m[0] = m[0]
ans = 1
for i in range(1, n):
  if m[i] >= max_m[i - 1]:
    ans = ans + 1
    max_m[i] = m[i]
  else:
    max_m[i] = max_m[i - 1]
print ans