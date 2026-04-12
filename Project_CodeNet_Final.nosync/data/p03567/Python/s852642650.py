S = input()
flag = False

for i in range(4):
    if S[i:i+2] == "AC":
        flag = True

print("Yes" if flag else "No")