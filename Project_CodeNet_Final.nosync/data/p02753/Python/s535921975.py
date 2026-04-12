import sys

s = sys.stdin.readline().strip()

first = s[0]

same = True
for letter in s:
    if letter != first:
        same = False

if same:
    print('No')
else:
    print('Yes')