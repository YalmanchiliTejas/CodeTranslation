import re
n=input()
s=input()
k=int(input())
print(re.sub("A",s[k-1],re.sub("[a-z]","*",re.sub(s[k-1],"A",s))))