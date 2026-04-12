S = input()
flag = True
for i in range(len(S)-1):
    if S[i]!=S[i+1]:
        flag = False
        break
print("No") if flag else print("Yes")