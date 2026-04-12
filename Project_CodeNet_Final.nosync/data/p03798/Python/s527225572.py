n = int(input())
l = list(input())

def che(k):
    if l[k] == "o":
        if ans[k] == 1:
            if ans[k-1]*ans[(k+1)%n] == 1:
                return True
            else:
                return False
        else:
            if ans[k-1]*ans[(k+1)%n] == -1:
                return True
            else:
                return False

    else:
        if ans[k] == 1:
            if ans[k-1]*ans[(k+1)%n] == -1:
                return True
            else:
                return False
        else:
            if ans[k-1]*ans[(k+1)%n] == 1:
                return True
            else:
                return False


check = [[1,1],[1,-1],[-1,1],[-1,-1]]
for j,k in check:
    ans = [0]*n
    ans[0] = j
    ans[1] = k
    
    for i in range(1,n):
        if ans[i] == 1:
            if l[i] == "o":
                ans[(i+1)%n] = ans[i-1]
            else:
                ans[(i+1)%n] = -ans[i-1]

        else:
            if l[i] == "o":
                ans[(i+1)%n] = -ans[i-1]
            else:
                ans[(i+1)%n] = ans[i-1]
    d = True
    
    for m in range(n):
        if che(m) == False:
            d = False
            
    if d:
        for i in ans:
            if i == 1:
                print("S",end="")
            else:
                print("W",end="")
        exit()  
            
print(-1)