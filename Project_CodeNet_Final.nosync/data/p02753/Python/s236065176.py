s=list(input())
a=0
b=0
for i in range(3):
    if s[i]=="A":
        a+=1
    else:
        b+=1
print("No" if a==3 or b==3 else "Yes")
#print(s)