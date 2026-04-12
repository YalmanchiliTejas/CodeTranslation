n=int(input())
s=[input() for _ in range(n)]
a=[[0 for _ in range(26)] for _ in range(n)]
for i in range(n):
    for t in list(s[i]):
        a[i][ord(t)-ord('a')]+=1
b=[]
for i in range(26):
    t=2147483647
    for j in range(n):
        t=min(t,a[j][i])
    b.append(t)
c=[]
for i in range(26):
    c+=chr(ord('a')+i)*b[i]
print("".join(c))