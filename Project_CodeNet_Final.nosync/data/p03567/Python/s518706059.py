S = input().strip()
flag = 0
for i in range(len(S)-2+1):
    if S[i:i+2]=="AC":
        flag = 1
        break
if flag==1:
    print("Yes")
else:
    print("No")