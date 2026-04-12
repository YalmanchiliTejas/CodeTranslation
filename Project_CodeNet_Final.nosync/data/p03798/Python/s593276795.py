N=int(input())
S=input()
ANS=-1
def check(s,a,b,c):
    if s=="o":
        if b=="S" and a==c:
            return True
        elif b=="W" and a!=c:
            return True
    else:
        if b=="S" and a!=c:
            return True
        elif b=="W" and a==c:
            return True
    return False
for start in ["SS","SW","WS","WW"]:
    ans=start
    for i in range(2,N):
        if S[i-1]=="o":
            if ans[i-2]==ans[i-1]:
                ans+="S"
            else:
                ans+="W"
        else:
            if ans[i-2]==ans[i-1]:
                ans+="W"
            else:
                ans+="S"
    if check(S[0],ans[N-1],ans[0],ans[1]) and check(S[N-1],ans[N-2],ans[N-1],ans[0]):
        ANS=ans
        break
print(ANS)