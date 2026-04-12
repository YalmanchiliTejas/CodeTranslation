S = input()
flag = 0
for i in range(len(S)-1):
    if S[i+1] != S[i]:
        flag = 1

if flag == 0:
    print("No")
else:
    print("Yes")