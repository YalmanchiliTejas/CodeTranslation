n = int(input())
str = input()
k = int(input())

c = str[k-1]
str2 = ""
for char in str:
  if char == c:
    str2 += c
  else:
    str2 += "*"
    
print(str2)