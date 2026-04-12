N=input()
s=list(input())
idx=int(input())
z=s[idx-1]
for it in s:
    if it == z:
        print(it,end="")
    else:
        print("*",end="")
print()
