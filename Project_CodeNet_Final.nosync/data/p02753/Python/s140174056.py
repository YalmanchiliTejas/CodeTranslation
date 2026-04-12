S = input()

tmp = S[0]
for i in range(3):
    if tmp !=S[i]:
        print("Yes")
        exit()
print("No")
