S=input()
i=0
p="No"
d=0
while i<len(S)-1 and d==0:
    if S[i]=="A" and S[i+1]=="C":
        d=1
    i+=1
if d==1:
    p="Yes"
print(p)