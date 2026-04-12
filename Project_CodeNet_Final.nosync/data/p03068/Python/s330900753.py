n = int(input())
s = list(input())#入力を一文字ずつリストに
k = int(input())
for i in range(n):
  if s[i] != s[k-1]:
    s[i] = "*"
ans = "".join(s)
print(ans)