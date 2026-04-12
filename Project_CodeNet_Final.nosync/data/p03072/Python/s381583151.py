n = input()
s = [int(i) for i in input().split()]
cnt = 1
tmp = s[0]
for i in range(1, len(s)):
  if s[i] >= tmp:
    cnt += 1
    tmp = s[i]
print(cnt)
    