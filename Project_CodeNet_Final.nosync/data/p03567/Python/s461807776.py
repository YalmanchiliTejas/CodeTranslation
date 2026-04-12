S = input()
for _ in range(len(S) - 1):
    if S[_:_ + 2] == "AC":
        print("Yes")
        break
else:
    print("No")
