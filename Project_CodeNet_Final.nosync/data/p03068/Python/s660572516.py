n = input()
s = input()
i = int(input())
 
l = list(s)
for j, c in enumerate(l):
  if c != s[i-1]:
    l[j] = '*'
    
l = ''.join(l)
 
print(l)