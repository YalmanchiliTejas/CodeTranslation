s = input()
for i in range(len(s)):
  if 'AC' in s:
    ans =1
  else:
    ans =0
print('Yes' if ans ==1 else 'No')