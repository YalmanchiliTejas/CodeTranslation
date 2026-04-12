N = int(input())
s= input()

def judge(start):
    ans = start
    for i in range(1, N):
        # 羊の処理
        if ans[i]=="S":
            # o or xで分岐
            if s[i]=="o":
                 ans[i+1]=ans[i-1]
            else:
                  # 羊x
                 ans[i+1]= "S" if ans[i-1]=="W" else "W"
        else:
            if s[i]=="o":
                # 狼o
                ans[i+1]= "S" if ans[i-1]=="W" else "W"
            else:
                  # 狼x
                 ans[i+1]=ans[i-1]

    # 判定
    if ans[0]==ans[N]:
        if ans[0]=="S":
            if s[0]=="o" and ans[1] == ans[N-1]:
                print("".join(ans[:-1]))
                exit()
            elif s[0]=="x" and ans[1] != ans[N-1]:
                print("".join(ans[:-1]))
                exit()
        elif ans[0]=="W":
            if s[0]=="o" and ans[1] != ans[N-1]:
                print("".join(ans[:-1]))
                exit()
            elif s[0]=="x" and ans[1] == ans[N-1]:
                print("".join(ans[:-1]))
                exit()
    else:
        return(-1)

judge(list("W"+"W"*(N)))
judge(list("W"+"S"*(N)))
judge(list("S"+"S"*(N)))
judge(list("S"+"W"*(N)))

print(-1)
