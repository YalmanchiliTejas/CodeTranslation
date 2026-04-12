S = input()
N = len(S)

for i in range(N - 1):
    if S[i : i + 2] == "AC":
        print("Yes")
        break
else:
    print("No")
