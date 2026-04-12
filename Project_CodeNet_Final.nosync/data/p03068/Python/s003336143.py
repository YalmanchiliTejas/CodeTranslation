_ = input()
s = input()
n = int(input())

ans = ""
for c in s:
  if c == s[n - 1:n]:
    ans += c
  else:
    ans += "*"
    
print(ans)