import re

n=int(input())
s=input()
k=int(input())

target=s[k-1]

s=s.replace(target, '0')
s=re.sub('[a-z]', "*", s)
s=s.replace('0', target)
print(s)
