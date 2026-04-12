n=int(input())
l=list(str(input()))
k=int(input())
a=l[k-1]
ans=[]
for i in range(n):
    if l[i]==a:ans.append(a)
    else:ans.append("*")
print("".join(ans))