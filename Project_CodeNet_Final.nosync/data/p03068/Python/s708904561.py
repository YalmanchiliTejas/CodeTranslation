n = int(input())
s = list(input())
k = int(input())

e = s[k - 1]

for i in range(n):
  if s[i] != e:
    s[i] = "*"

print("".join(s))
