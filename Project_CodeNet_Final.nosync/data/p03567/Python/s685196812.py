S = input()
yes = False
for i in range(len(S) - 1):
    if S[i:i + 2] == "AC":
        yes = True
    
if yes:
    print("Yes")
else:
    print("No")