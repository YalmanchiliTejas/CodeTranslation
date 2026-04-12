s=input()
count=0
for i in range(0,len(list(s))-1):
    if(s[i]!=s[i+1]):
        count+=1
    elif(s[i]==s[i+1]):
        count+=0

if(count>1 or count==1):
    print("Yes")
else:
    print("No")
