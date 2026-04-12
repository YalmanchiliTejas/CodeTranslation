import sys
n = int(input())
s = input()
k = int(input())

for i in range(n):
    if s[i]!=s[k-1]:
        sys.stdout.write("*")
    else:
        sys.stdout.write(s[k-1])
