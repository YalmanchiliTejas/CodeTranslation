import re
ptr=["A{3}|B{3}"]
str=input()

for valueptr in ptr:
    pattern=re.compile(valueptr)
    res=pattern.search(str)
    if res is None:
        print("Yes")
    else:
        print("No")