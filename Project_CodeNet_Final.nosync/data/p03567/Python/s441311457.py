S = input()
for k in range(1,len(S)):
    if S[k-1:k+1] == "AC":
        print("Yes")
        exit(0)
print("No")