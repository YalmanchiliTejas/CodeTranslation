
s=input()

try:
    res=s.index("AC")
except:
    res=-1

if res>=0:
    print("Yes")
else:
    print("No")
