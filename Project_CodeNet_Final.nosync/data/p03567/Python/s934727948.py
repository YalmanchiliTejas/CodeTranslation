S = input()
f = False
for i in range(S.__len__()-1):
    f |= S[i:i+2] == "AC"

print("Yes" if f else "No")
