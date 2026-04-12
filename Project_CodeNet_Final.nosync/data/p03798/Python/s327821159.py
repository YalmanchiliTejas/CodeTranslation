N = int(input())
s = list(input())
rev = {"S":"W","W":"S"}

ok = False
for x,y in [("S","S"),("S","W"),("W","S"),("W","W")]:
    ans = [x,y]+["a"]*(N-2)

    for i in range(1,N-1):
        if ans[i]=="S" and s[i]=="o":
            ans[i+1]=ans[i-1]
        elif ans[i]=="S" and s[i]=="x":
            ans[i+1]=rev[ans[i-1]]
        elif ans[i]=="W" and s[i]=="o":
            ans[i+1]=rev[ans[i-1]]
        elif ans[i]=="W" and s[i]=="x":
            ans[i+1]=ans[i-1]

    if ans[N-1]==ans[1] and ((s[0]=="o" and ans[0]=="S") or (s[0]=="x" and ans[0]=="W")):
        ok = True
    if ans[N-1]!=ans[1] and ((s[0]=="x" and ans[0]=="S") or (s[0]=="o" and ans[0]=="W")):
        ok = True

    if not ok:
        continue
    
    ok=False
    if ans[N-2]==ans[0] and ((s[N-1]=="o" and ans[N-1]=="S") or (s[N-1]=="x" and ans[N-1]=="W")):
        ok = True
    if ans[N-2]!=ans[0] and ((s[N-1]=="x" and ans[N-1]=="S") or (s[N-1]=="o" and ans[N-1]=="W")):
        ok = True

    if ok:
        break

if ok:
    print("".join(ans))
else:
    print(-1)
            