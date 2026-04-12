S = str(input())
for i in range(4):
    if S[i:i+2]=="AC":
        print("Yes")
        exit()
print("No")
