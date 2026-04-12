_  = input()
s = input()
index = int(input())-1

result = ''

t = s[index]

for i in s:
  if i != t:
    result += '*'
  else:
    result += i
print(result)