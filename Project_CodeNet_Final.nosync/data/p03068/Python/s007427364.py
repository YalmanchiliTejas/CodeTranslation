n = int(input().strip())
s = input().strip()
k = int(input().strip())

str= list(s)
target = str[k-1]

for i in range(n):
  if str[i] != target:
    str[i] = "*"

s_c = "".join(str) 

print(s_c)