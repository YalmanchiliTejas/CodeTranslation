import sys
input = sys.stdin.readline

n = int(input())
s = input().rstrip("\r\n")
k = int(input())
ans = ''
for c in s:
    if c != s[k-1]:
        ans += '*'
        continue
    ans += c
print(ans)