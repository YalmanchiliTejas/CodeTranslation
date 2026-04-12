from collections import Counter
s=input()
c=Counter(s)
if(len(c.keys())==1):
    print ("No")
else:
    print ("Yes")