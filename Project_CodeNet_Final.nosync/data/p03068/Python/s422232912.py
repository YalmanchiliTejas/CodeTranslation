n = int(input())
s = list(input())
k = int(input())
ans = ''
m = s[k-1]
for ss in s:
  if ss == m:
    ans += ss
  else:
    ans += '*'
print(ans)