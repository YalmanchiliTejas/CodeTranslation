S=input()
c=0
for i in range(len(S)-1):
    if S[i]!=S[i+1]:
        c=c+1
        break 
if c==0:
    print("No")
else :
    print("Yes")