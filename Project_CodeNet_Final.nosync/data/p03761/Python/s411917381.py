from collections import Counter
n = int(input())
li = [0]*n

for i in range(n):
    li[i] = Counter(input())

ans = [50]*26
for i in range(ord("a"),ord("z")+1):
    for j in range(n):
        ans[i-97] = min(li[j][chr(i)],ans[i-97])
s = ""
for i in range(26):
    if ans[i] != 0:
        s += chr(i + ord("a"))*ans[i]
s = list(s)
s.sort()
print("".join(s))