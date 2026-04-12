def sep():
    return map(int,input().strip().split(" "))
def lis():
    return list(sep())


s=input()
from collections import Counter
c=Counter(s)
if len(c.keys())>=2:
    print("Yes")
else:
    print("No")