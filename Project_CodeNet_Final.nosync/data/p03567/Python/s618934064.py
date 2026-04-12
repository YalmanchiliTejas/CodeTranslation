s=input()
f=0
for i in range(1,len(s)):
    if s[i-1:i+1]=="AC":
        f=1
        break
print("Yes" if f else "No")
