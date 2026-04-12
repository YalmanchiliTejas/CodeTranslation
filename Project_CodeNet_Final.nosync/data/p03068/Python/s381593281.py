n = int(input())
s = input()
k = int(input())
letter = s[k-1]
for i in s:
  if i != letter:
    s = s.replace(i, "*")
print(s)