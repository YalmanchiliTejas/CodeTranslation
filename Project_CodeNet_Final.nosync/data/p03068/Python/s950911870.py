n = int(input())
s = input()
k = int(input())


slist = []
for ss in s:
    if ss == s[k-1]:
        slist.append(ss)
    else:
        slist.append('*')

import sys
for ss in slist:
    sys.stdout.write(ss)
print()


