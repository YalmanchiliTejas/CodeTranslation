n = int(input())
s = list(input())
k = int(input())-1
l = s[k]
for i in range(n):
  s[i] = l*(s[i] == l) or "*"
print("".join(s))