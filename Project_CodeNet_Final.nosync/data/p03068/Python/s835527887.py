n = int(input())
s = input()
k = int(input())

target = s[k-1]

for i in range(len(s)):
  if target != s[i]:
    s = s[:i] + "*" + s[i+1:]
    
print(s)