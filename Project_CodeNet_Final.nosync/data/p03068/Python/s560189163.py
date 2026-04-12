n = int(input())
s = list(str(input()))
k = int(input())
for i in range(n):
  if s[i] is not s[k-1]:
    s[i] = "*"
print("".join(s))