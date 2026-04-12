S = input()
judge = 0
for i in range(len(S)):
    if S[i] == "A" and S[i+1] == "C":
        judge = 1
        break
if judge == 1:
    print("Yes")
else:
    print("No")