import re
n,s,k=open(0)
print(re.sub("[^" + s[int(k)-1] + "]", "*", s[:-1]))