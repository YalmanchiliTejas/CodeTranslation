n = int(input())
s = input()
k = int(input())
m = s[k-1]

for i in range(n):
  if s[i] != m:
    s = s.replace(s[i], "*")
print(s)