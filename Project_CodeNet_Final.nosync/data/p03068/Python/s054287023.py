n = int(input())
s = input()
k = int(input())
x = ""
for i in range(n):
  if s[i] == s[k-1]:
    x = x+s[i]
  else:
    x = x+"*"
print(x)