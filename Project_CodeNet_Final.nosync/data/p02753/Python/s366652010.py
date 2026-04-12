S = input()
count = 0
for i in range(len(S)):
    if S[0] == S[i]:
        count += 1
if count == 3:
    print("No")
else:
    print("Yes")