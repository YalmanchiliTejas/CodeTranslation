S=input()
Aflug=False
Bflug=False

for i in range(3):
    if S[i]=="A":
        Aflug=True
    else:
        Bflug=True

if Aflug==True and Bflug==True:
    print("Yes")
else:
    print("No")