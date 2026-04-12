_ = input()
s = input()
target = int(input()) - 1

result = []
for c in s:
  if c != s[target]:
    result.append('*')
  else:
    result.append(c)
    
print(''.join(result))