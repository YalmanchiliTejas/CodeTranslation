import sys

n = int(input()) 
s = list(input()) 
k = int(input()) 

word = s[k-1]
for i in s:
    if i != word:
        sys.stdout.write('*')
    else:
        sys.stdout.write(i)