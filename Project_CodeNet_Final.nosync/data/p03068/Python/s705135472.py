n=input()
s=input()
m=s[int(input())-1]
for x in s:
    if m==x:p=x
    else:p="*"
    print(p,end="")
print()