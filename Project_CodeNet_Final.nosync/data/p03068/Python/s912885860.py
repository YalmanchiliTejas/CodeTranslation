n = int(input())
s = input()
k = int(input())
x = s[k - 1]
ans = s
for i in range(0, n, 1):
  if s[i] != x:
    ans = ans.replace(s[i], '*')
print(ans)
