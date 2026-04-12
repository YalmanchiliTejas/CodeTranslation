n = int(input())
s = input()
k = int(input())

c = s[k-1]

for i in range(n):
  if s[i] != c:
    s = s.replace(s[i], '*')

print(s)