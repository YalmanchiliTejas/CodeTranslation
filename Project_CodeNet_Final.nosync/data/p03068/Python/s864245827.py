n = int(input())
s = input()
k = int(input())
s = list(s)
tmp = s[k-1]
for i in range(n):
  if tmp != s[i]:
    s[i] = '*'
    
s = ''.join(s)
print(s)
