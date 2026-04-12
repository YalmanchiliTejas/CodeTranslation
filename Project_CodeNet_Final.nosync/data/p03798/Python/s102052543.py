n=int(input())
s=input()
ans1="SS"
ans2="SW"
ans3="WS"
ans4="WW"

def check(ans):
    for i in range(1,n-1):
        if s[i]=="o"  and ans[i]=="S":
            ans+=ans[i-1]
        elif s[i]=="o" and ans[i]=="W":
            if ans[i-1]=="W":
                ans+="S"
            else:
                ans+="W"
         
        elif s[i]=="x"  and ans[i]=="S":
            if ans[i-1]=="W":
                ans+="S"
            else:
                ans+="W"
        elif s[i]=="x" and  ans[i]=="W":
            ans+=ans[i-1]
    flg=False
    if s[n-1]=="o":
        if ans[n-1]=="S":
            if ans[0]==ans[n-2]:
                flg=True
    if s[n-1]=="o":
        if ans[n-1]=="W":
            if ans[0]!=ans[n-2]:
                flg=True
    if s[n-1]=="x":
        if ans[n-1]=="S":
            if ans[0]!=ans[n-2]:
                flg=True
    if s[n-1]=="x":
        if ans[n-1]=="W":
            if ans[0]==ans[n-2]:
                flg=True
    if flg:
        if s[0]=="o":
            if ans[0]=="S":
                if ans[1]==ans[n-1]:
                    print(ans)
                    exit()
        if s[0]=="o":
            if ans[0]=="W":
                if ans[1]!=ans[n-1]:
                    print(ans)
                    exit()
        if s[0]=="x":
            if ans[0]=="S":
                if ans[1]!=ans[n-1]:
                    print(ans)
                    exit()
        if s[0]=="x":
            if ans[0]=="W":
                if ans[1]==ans[n-1]:
                    print(ans)
                    exit()
check(ans1)
check(ans2)
check(ans3)
check(ans4)
print(-1)