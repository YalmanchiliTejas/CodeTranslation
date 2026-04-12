S=input()
A=S[0]
flag=False
for i in S:
    if A!=i:
        flag=True

if flag:
    print("Yes")
else:
    print("No")
