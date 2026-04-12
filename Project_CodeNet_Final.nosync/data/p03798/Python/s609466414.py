N = int(input())
s = input()
SW_list = ["SS", "SW", "WS", "WW"]
check = False
for sw in SW_list:
    ans = [""] * N
    ans[0] = sw[0]
    ans[1] = sw[1]
    for i in range(1, N-1):
        if (ans[i] == "S" and s[i] == "o") or (ans[i] == "W" and s[i] == "x"):
            ans[i+1] = ans[i-1]
        else:
            ans[i+1] = "S" if ans[i-1] == "W" else "W"
    if (ans[0] == "S" and s[0] == "o") or (ans[0] == "W" and s[0] == "x"):
        if ans[1] == ans[-1]:
            check = True
    else:
        if ans[1] != ans[-1]:
            check = True
    if (ans[-1] == "S" and s[-1] == "o") or (ans[-1] == "W" and s[-1] == "x"):
        if ans[0] != ans[-2]:
            check = False
    else:
        if ans[0] == ans[-2]:
            check = False
    if check:
        print(*ans, sep="")
        break

if check == False:
    print(-1)