s = input()
s1 = s[:1]
s2 = s[1:2]
s3 = s[2:]

if s1 == s2 and s2 == s3:
  print('No')
else:
  print('Yes')