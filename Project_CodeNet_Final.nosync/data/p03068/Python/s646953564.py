n=int(input())
s=input()
k=int(input())
t=s[k-1]
l=[]
for i in s:
    if i==t:
        l.append(i)
    else:
        l.append("*")
print("".join(l))