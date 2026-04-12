n=int(input())
a=[0]*26
S=input()
for i in S:
    a[ord(i)-97]+=1
for _ in range(n-1):
    l=[0]*26
    S=input()
    for i in S:
        l[ord(i)-97]+=1
    for i in range(26):
        a[i]=min(a[i],l[i])
for i in range(26):
    print((chr(i+97)*a[i]),end="")