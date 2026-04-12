S=list(input())

S.sort()
if S[-1]=="A" or S[0]=="B":
    print("No")
else:
    print("Yes")