n=int(input())
s=list(str(input()))
k=int(input())
a=[]
for i in range(n):
    if s[k-1]==s[i]:
        a.append(s[k-1])
    else:
        a.append("*")
b="".join(a)
print(b)