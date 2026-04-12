N = int(input())
S = list(input())

for a in [["S","S"],["S","W"],["W","S"],["W","W"]]:
    ans = a[0]+a[1]
    for i in range(1,N-1):
        if S[i] == "o":
            if ans[i] == "S" and ans[i-1] == "S":
                ans += "S"
            elif ans[i] == "S" and ans[i-1] == "W":
                ans += "W"
            elif ans[i] =="W" and ans[i-1] == "S":
                ans += "W"
            elif ans[i] =="W" and ans[i-1] == "W":
                ans += "S"
        elif S[i] == "x":
            if ans[i] == "S" and ans[i-1] == "S":
                ans += "W"
            elif ans[i] == "S" and ans[i-1] == "W":
                ans += "S"
            elif ans[i] =="W" and ans[i-1] == "S":
                ans += "S"
            elif ans[i] =="W" and ans[i-1] == "W":
                ans += "W"

    if S[-1] == "o":
        if ans[-1] == "S":
            if ans[-2] != ans[0]:
                ans = ""
        else:
            if ans[-2] == ans[0]:
                ans = ""
    elif S[-1] == "x":
        if ans[-1] == "S":
            if ans[-2] == ans[0]:
                ans = ""
        else:
            if ans[-2] != ans[0]:
                ans = ""
    
    if ans == "":
        continue

    if S[0] == "o":
        if ans[0] == "S":
            if ans[1] != ans[-1]:
                ans = ""
        else:
            if ans[1] == ans[-1]:
                ans = ""
    elif S[0] == "x":
        if ans[0] == "S":
            if ans[1] == ans[-1]:
                ans = ""
        else:
            if ans[1] != ans[-1]:
                ans = ""
    
    if ans != "":
        print(ans)
        exit()
print(-1)
            

