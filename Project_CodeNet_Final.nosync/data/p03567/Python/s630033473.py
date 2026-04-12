s=input()
n=len(s)
for i in range(n-1):
    if s[i]=="A" and s[i+1]=="C":
        print("Yes")
        exit()
print("No")