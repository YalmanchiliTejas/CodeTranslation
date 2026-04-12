import sys

S=sys.stdin.readline()
m={}
for s in S:
    m[s] = True
if "A" in m and "B" in m:
    print("Yes")
else:
    print("No")
