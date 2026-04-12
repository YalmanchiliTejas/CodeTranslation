s=input()
a=0
for i in range(1,len(s)):
    if s[i-1]+s[i]=="AC":
        print("Yes")
        a=1
        break
if a==0:
    print("No")
