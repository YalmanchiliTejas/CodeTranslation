input();s=input();k=int(input())
c=""
d=s[k-1]
for i in s:
    if i!=d:
        c+="*"
    else:
        c+=d
print(c)