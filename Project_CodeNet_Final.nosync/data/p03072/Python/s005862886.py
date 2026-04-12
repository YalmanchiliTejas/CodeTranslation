N = int(input())
s = input().split()
count = 1
for i in range(N):
  s[i] = int(s[i])
for i in range(1,N):
  t = s[:i]
  if max(t) <= s[i]:
    count = count + 1
print(count)
