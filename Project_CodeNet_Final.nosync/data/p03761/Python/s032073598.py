n=int(input())
s=[input() for i in range(n)]

a=ord("a")
l=[50]*26

for i in s:
    for j in range(26):
        l[j] = min(l[j],i.count(chr(a+j)))

for i in range(26):
    for kk in range(l[i]):
        print(chr(a+i),end="")
