a = int(input())
word = input()
b = int(input())
c = []
d = ""
for i in range(a):
  if word[i] != word[b-1]:
    c.append("*")
  else:
    c.append(word[i])
for i in range(a):
  d += c[i]
print(d)