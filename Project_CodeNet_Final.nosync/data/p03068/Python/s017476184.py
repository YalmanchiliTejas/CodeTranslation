n = int(input())
s = list(input())
c = int(input())
for i in range(0,n):
  if s[i] == s[c-1]:
    continue
  else:
    s[i] = '*'
    
str = ''.join(s)

print(str)
  