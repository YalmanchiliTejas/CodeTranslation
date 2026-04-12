n = int(input())
str = input()
str =list(str)
str.append("a")
cs = int(input())

char = str[cs-1]
for i in range(n):
  if str[i] != char:
    str[i:i+1] = "*"
ans = str[0:n]

print(*ans,sep ="")

