S=input()
ans=[]
for i in range(3):
    ans.append(S[i])
if len(set(ans))!=1:
    print("Yes")
else:
    print("No")