n=int(input())
s=input()
k=int(input())
a=s[k-1]
for i in range(n-1):
    if s[i]!=a:
        print("*",end="")
    else:
        print(s[i],end="")
if s[n-1]!=a:
    print("*")
else:
    print(s[n-1])