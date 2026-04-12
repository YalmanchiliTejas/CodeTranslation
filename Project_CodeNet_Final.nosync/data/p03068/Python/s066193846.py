import re
n=input()
s=input()
k=int(input())
print(re.sub("[^"+s[k-1]+"]","*",s))