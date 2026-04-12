S = input()
n = len(S)

for i in range(n-1):
    if "AC" in S:
        print("Yes")
        exit()

print("No")