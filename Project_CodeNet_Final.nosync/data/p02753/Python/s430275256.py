S = str(input())
flag = 0
for i in range(len(S)-1):
    if S[i]!=S[i+1]:
        flag = 1
if flag == 1:
    print("Yes")
else:
    print("No")