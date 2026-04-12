n = int(input())
s = input()
k = int(input())
a = s[k - 1]
for j in range(n):
  if s[j] == a:
    None
  else:
      s = s.replace(s[j],"*")
print(s)