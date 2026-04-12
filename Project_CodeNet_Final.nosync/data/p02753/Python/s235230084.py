from sys import stdin

s = stdin.readline().rstrip()

count = 0
if s[0] == 'A':
    if s[1] == 'B':
        count += 1
if s[1] == 'A':
    if s[2] == 'B':
        count += 1
if s[0] == 'B':
    if s[1] == 'A':
        count += 1
if s[1] == 'B':
    if s[2] == 'A':
        count += 1
if count > 0:
    print('Yes')
else:
    print('No')
