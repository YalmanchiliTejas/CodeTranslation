S=input()
flag=0
for i in range(len(S)-1):
    #print(S[i:i+2])
    if S[i:i+2]=="AC":
        print("Yes")
        flag=1
        break
if flag==0:
    print ("No")