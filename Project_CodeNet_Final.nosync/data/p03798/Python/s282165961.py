


N = int(input())
S = input()



# 1,Nをヒツジと狼のどちらかと仮定して場合分け

for s1,sn in [("S","S"), ("S","W"), ("W","S"), ("W","W")]:
    ans = [""]*(N+2)
    ans[1] = s1
    ans[0] = sn
    for i in range(1,N+1):
       
        if ans[i] == "S":

            if S[i-1] == "o":
                ans[i+1] = "S" if ans[i-1] =="S" else "W"
            else:
                ans[i+1] = "W" if ans[i-1] =="S" else "S"
        else:
            if S[i-1] == "o":
                ans[i+1] = "S" if ans[i-1] =="W" else "W"
            else:
                ans[i+1] = "W" if ans[i-1] =="W" else "S"

    if ans[0] == ans[N] and ans[1] == ans[N+1]:
        print("".join(ans[1:N+1]))
        exit()

print(-1)