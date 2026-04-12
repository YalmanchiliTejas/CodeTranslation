import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline()
k = int(sys.stdin.readline())

ch = s[k - 1:k]
ans = ''
for i in range(n):
    tmp = s[i:i + 1]
    if tmp in list(ch):
        ans += tmp
    else:
        ans += '*'
print(ans)
