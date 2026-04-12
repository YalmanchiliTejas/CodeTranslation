n = int(input())
s = input()
k = int(input())
for i in range(n):
  if s[i] != s[k-1]:
    s = s.replace(s[i], '*')
print(s)
