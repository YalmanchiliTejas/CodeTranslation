n = int(input())
s =[[0]*26 for i in range(n)]
a =[50]*26
sa=''
for i in range(n):
    s1=list(input())
    for j in s1:
        s[i][ord(j)-ord('a')]+=1
for j in range(26):
    for i in range(n):
        if a[j]>s[i][j]:
            a[j]=s[i][j]
for i in range(26):
    sa+=chr(ord('a')+i)*a[i]
print(sa)
