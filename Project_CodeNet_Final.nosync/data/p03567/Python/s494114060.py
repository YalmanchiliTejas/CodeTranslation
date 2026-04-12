a=input().rstrip()
l=len(a)
flag=False
for i in range(l-1):
    if(a[i:i+2]=="AC"):
        flag=True

print(("No" if flag==False else "Yes"),flush=True)
 