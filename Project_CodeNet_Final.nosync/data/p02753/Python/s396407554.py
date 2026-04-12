S = input()

now = S[0]
for i in range(1, 3):
    if now != S[i]:
        print("Yes")
        exit()

print("No")
