n=int(input())
s=input()
k=s[int(input())-1]
p=[]
for i in s:
    if i!=k:p.append("*")
    else:p.append(k)
print("".join(p))