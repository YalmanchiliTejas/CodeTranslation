S = input()

flag = False

if S[0] != S[1]:
    flag = True

if S[1] != S[2]:
    flag = True

if flag:
    print("Yes")

else:
    print("No")
