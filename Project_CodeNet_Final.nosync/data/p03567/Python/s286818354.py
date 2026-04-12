s=input()
res=[]
for i in range(len(s)-1):
    res.append(s[i:i+2])
print("Yes" if "AC" in res else "No")