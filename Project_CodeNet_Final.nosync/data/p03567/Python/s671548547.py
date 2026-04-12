#Can you get AC?
S = input()
n = len(S)
p = 0
for i in range(n-1):
    if S[i:i+2] == "AC":
        print("Yes")
        p = p + 1
        break
    else:
        continue
if p == 0:
    print("No")