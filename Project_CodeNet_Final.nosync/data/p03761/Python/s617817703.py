import sys
import bisect
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
n = int(readline())

lst1 = [[0]*26 for _ in range(n)]
kijun = ord("a")
for i in range(n):
    s = readline().rstrip().decode('utf-8')
    for j in s:
        lst1[i][ord(j)-kijun] += 1

ans = [100]*26

for i in lst1:
    for j in range(26):
        ans[j] = min(ans[j],i[j])

res = ""
for i in range(26):
    if ans[i] != 0:
        res += chr(kijun+i)*ans[i]

print(res)
