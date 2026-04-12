n = int(input())
s = input()
k = int(input())
ch = s[k - 1]
output = []
for i in range(n):
  if (s[i] == ch):
    output.append(ch)
  else:
    output.append('*')
o = ''.join(output)
print(o)