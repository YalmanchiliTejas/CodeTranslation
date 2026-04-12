N = list(input())
flag = 0
for i in range(0, len(N)):
    if N[i] == "C" and N[i - 1] == "A":
        flag = 1

if flag == 1:
    print("Yes")
else:
    print("No")