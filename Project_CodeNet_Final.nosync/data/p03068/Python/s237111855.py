from sys import stdin
n = int(stdin.readline().rstrip())
s = stdin.readline().rstrip()
k = int(stdin.readline().rstrip())

key = s[k-1]
sin = ""
for i in s:
    if i != key:
        sin += "*"
    else:
        sin += i
print(sin)