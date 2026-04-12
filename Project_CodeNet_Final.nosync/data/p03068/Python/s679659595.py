n = int(input())
s = input()
k = int(input())

x = s[k-1]
temp_list = []

for c in s:
  if c is not x:
    temp_list.append('*')
  else:
    temp_list.append(c)

print(''.join(temp_list))