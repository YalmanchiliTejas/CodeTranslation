S=list(input())
countA=0
countB=0
for i in range(3):
    if S[i]=="A":
        countA+=1
    else:
        countB+=1
if countA!=0 and countB!=0:
    print("Yes")
else:
    print("No")    