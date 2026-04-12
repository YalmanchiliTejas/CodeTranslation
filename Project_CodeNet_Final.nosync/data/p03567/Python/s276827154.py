n=input()
c=0
for i in range(1,len(n)):
    if n[i-1:i+1]=="AC":
        c=1
print("Yes"if c!=0else"No")