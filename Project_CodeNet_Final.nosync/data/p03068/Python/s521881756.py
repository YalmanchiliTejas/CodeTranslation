n = int(input())
s = input()
k = int(input())
r = ""
for i in s:
  if i == s[k-1]:
    r += i
  else:
    r+='*'
print(r)