N = int(input())
s = input()
k = int(input())
l = []
for i in range(N):
    l.append(s[i])

for i in range(N):
    if l[i] != s[k - 1]:
        l[i] = "*"
print(*l,sep="")