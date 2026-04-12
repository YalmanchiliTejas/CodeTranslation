S = input()
n = len(S)

for i in range(n-1):
    if S[i:i+2] == "AC":
        print("Yes")
        exit()

print("No")