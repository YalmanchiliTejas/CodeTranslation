n = int(input())
s = list(input())
k = int(input())
 
 
for i in range(0,n):
  if s[i] != s[k-1]:
    s[i] = '*'

s = "".join(s)
print(s)
