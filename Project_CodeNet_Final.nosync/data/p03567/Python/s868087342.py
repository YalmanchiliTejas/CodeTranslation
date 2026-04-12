S = list(input())
ans = -1
for i in range(1, len(S)):
    if S[i - 1] == "A" and S[i] == "C":
        print("Yes")
        ans = 1
        break
if ans == -1:
    print("No")
