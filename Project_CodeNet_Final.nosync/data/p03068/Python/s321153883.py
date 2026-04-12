n=int(input())
s=list(input())
k=int(input())

a=s[k-1]
for i in range(len(s)):
    if s[i]!=a:
        s.pop(i)
        s.insert(i,"*")
s="".join(s)
print(s)