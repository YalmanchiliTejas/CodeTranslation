n = int(input())
s = str(input())
k = int(input())

sk = s[k-1]
ans = []
for ss in s:
  if ss == sk:
    ans.append(ss)
  else:
    ans.append("*")
a = ''.join(ans)
print(a)