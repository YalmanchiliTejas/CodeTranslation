n=int(input())
a=[100]*26
for i in range(n):
    s=input()
    for j in range(26):
        a[j]=min(a[j],s.count(chr(ord('a')+j)))
for i in range(26):
    print(chr(ord('a')+i)*a[i],end='')