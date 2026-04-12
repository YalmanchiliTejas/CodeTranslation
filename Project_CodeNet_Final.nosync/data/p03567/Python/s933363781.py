a=list(raw_input())

ch=0

for i in a:
    if ch==0 and i=="A":
        ch=1
    elif ch==1:
        if i=="C":
            ch=2
            break
        else:
            ch=0

if ch==2:
    print "Yes"
else:
    print "No"