n=int(input())
s=input()
k=int(input())
a=s[k-1]
b=[]
for i in s:
    if a!=i:
        b.append(i)
for i in b:
    s=s.replace(i,"*")
print(s)