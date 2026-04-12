s=raw_input("")
temp=temp1=0
for i in range(3):
    if (s[i]=="A"):
        temp=1
    if (s[i]=="B"):
        temp1=1
if(temp*temp1):
    print "Yes"
else:
    print "No"