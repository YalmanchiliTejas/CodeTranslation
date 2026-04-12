import collections

n = int(input())
s = [list(input()) for i in range(n)]

for i in range(n):
    s[i] = collections.Counter(s[i])

ans=[100] *28
for i in range(28):
    for j in range(n):
        if s[j][chr(i+97)]<=ans[i]:
            ans[i]=s[j][chr(i+97)]
x=''

for i in range(28):
    if ans[i]!=0:
        for j in range(ans[i]):
            x+=chr(i+97)

print(x)