S=input()
for i in range(len(S)-1):
    if (S[i]=="A")&(S[i+1]=="C"):
        print("Yes")
        break
else:
    print("No")