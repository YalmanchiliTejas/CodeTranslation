s=input()
yn=0
for i in range(len(s)-1):
    if s[i:i+2]=="AC":
        yn=1
        break
if yn==1:
    print("Yes")
else:
    print("No")
