import sys
n=int(input())
s=list(input())
for i in range(n):
    if s[i]=="o":
        s[i]=0
    else:
        s[i]=1
s.append(s[0])
#"1"は羊、"0"は狼
data=["11","10","01","00"]
anser=""
for ans in data:
    qqq=ans
        
    for i in range(1,n+1):
        if ans[i]=="1":
            ans+=str((int(ans[i-1])+s[i])%2)
        else:
            ans+=str((int(ans[i-1])+s[i]+1)%2)
    if ans[n:]==qqq:
        anser=ans[:n]
        break
else:
    print(-1)
    sys.exit()
anser=list(anser)
for i in range(n):
    if anser[i]=="1":
        anser[i]="S"
    else:
        anser[i]="W"
print("".join(anser))