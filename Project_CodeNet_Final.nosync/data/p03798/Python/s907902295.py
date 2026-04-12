n=int(input())
s=input()
L=[]
done=False

for c in s:
    if c=="o":
        L.append(0)
    else:
        L.append(1)

ans="00"
for i in range(3,n+1):
    ans+=str((int(ans[i-3])+int(ans[i-2])+L[i-2])%2)

#print(ans)
if int(ans[0])==(int(ans[-1])+int(ans[-2])+L[-1])%2 and int(ans[1])==(int(ans[0])+int(ans[-1])+L[0])%2:
    pass

else:    
    ans="01"
    for i in range(3,n+1):
        ans+=str((int(ans[i-3])+int(ans[i-2])+L[i-2])%2)
    
    #print(ans)
    if int(ans[0])==(int(ans[-1])+int(ans[-2])+L[-1])%2 and int(ans[1])==(int(ans[0])+int(ans[-1])+L[0])%2:
        pass
    else:    
        ans="10"
        for i in range(3,n+1):
            ans+=str((int(ans[i-3])+int(ans[i-2])+L[i-2])%2)
        
        #print(ans)
        if int(ans[0])==(int(ans[-1])+int(ans[-2])+L[-1])%2 and int(ans[1])==(int(ans[0])+int(ans[-1])+L[0])%2:
            pass
        else:    
            ans="11"
            for i in range(3,n+1):
                ans+=str((int(ans[i-3])+int(ans[i-2])+L[i-2])%2)
            
            #print(ans)
            pass
            if int(ans[0])==(int(ans[-1])+int(ans[-2])+L[-1])%2 and int(ans[1])==(int(ans[0])+int(ans[-1])+L[0])%2:
                #print("!")
                pass
            else:
                print(-1)
                done=True

if not done:
    pri=""
    for c in ans:
        if c =="0":
            pri+="S"
        else:
            pri+="W"
    print(pri)
        