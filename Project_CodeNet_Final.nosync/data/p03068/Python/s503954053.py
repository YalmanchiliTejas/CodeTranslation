import re
int(input())
s=input()
print(re.sub('[^{}]'.format(s[int(input())-1]),"*",s))