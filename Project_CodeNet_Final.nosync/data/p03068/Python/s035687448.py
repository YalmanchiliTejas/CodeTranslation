n = int(input())
s = input()
pivot = s[int(input())-1]

for c in s:
  print(c if c == pivot else '*', end='')
  
print()