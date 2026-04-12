n = int(input())
s = [0]*n
import collections
t = [0]*n
for i in range(n):
    s[i] = input()
    t[i] = collections.Counter(s[i])
m = [100]*26
ans = []
for A in t:
    for i in range(26):
        m[i] = min(m[i],A[chr(97+i)])
for i in range(26):
    if m[i] != 100 and m[i] != 0:
        ans.append([chr(97+i)]*m[i])
for A in ans:
    print("".join(A),end="")
print("")
