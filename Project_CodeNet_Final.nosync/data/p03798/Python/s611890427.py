n = int(input())
l = list(input())
l += l[0]


check = [[1,1],[1,-1],[-1,1],[-1,-1]]
for j,k in check:
    
    ans=[j,k]
    
    for i in range(1,n+1):
        if ans[i] == 1:
            if l[i] == "o":
                ans.append(ans[i-1])
            else:
                ans.append(-ans[i-1])

        else:
            if l[i] == "o":
                ans.append(-ans[i-1])
            else:
                ans.append(ans[i-1])
    
    if ans[1] == ans[-1] and ans[0] == ans[-2]:
        for i in ans[:-2]:
            if i == 1:
                print("S",end="")
            else:
                print("W",end="")
        exit()  
            
print(-1)