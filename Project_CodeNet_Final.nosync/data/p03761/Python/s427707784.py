from collections import Counter
import string
import sys
def II(): return int(sys.stdin.readline())
def IS(): return input()
def C(x): return Counter(x)

n = II()
s = sorted([IS() for _ in range(n)])
counter = []
for i in range(len(s)):
    counter.append(C(s[i]))
ans = []
for char in string.ascii_lowercase:
    mini = 50
    for c in counter:
        mini = min(mini, c[char])
    ans.append(char * mini)
print(''.join(ans))