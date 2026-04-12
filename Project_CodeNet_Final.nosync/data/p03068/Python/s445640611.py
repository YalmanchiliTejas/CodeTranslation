n = int(input())
s = list(input())
k = int(input())
si = s[k-1]
for i in range(n):
    if s[i] != si:
        s[i] = '*'
str_s = ''
for i in range(n):
  str_s += s[i]
print(str_s)