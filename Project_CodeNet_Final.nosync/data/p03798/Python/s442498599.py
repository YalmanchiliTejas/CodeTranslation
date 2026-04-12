n=int(input())
s=input()
def e(c):
    if c=="S":
        return "W"
    else:
        return "S"

def f(s1,sn,s2):
    ans=[""]*n
    ans[0]=s1
    ans[1]=s2
    for i in range(1,n-1):
        if s[i]=="o":
            if ans[i]=="S":
                ans[i+1]=ans[i-1]
            else:
                ans[i+1]=e(ans[i-1])
        else:
            if ans[i]=="W":
                ans[i+1]=ans[i-1]
            else:
                ans[i+1]=e(ans[i-1])
    if ans[-1]!=sn:
        return False
    elif s[-1]=="o":
        if ans[-1]=="S":
            if ans[-2]==ans[0]:
                return ans
        else:
            if ans[0]==e(ans[-2]):
                return ans
    else:
        if ans[-1]=="W":
            if ans[-2]==ans[0]:
                return ans
        else:
            if ans[0]==e(ans[-2]):
                return ans
    return False

if s[0]=="o":
    if f("S","S","S"):
        print(*f("S","S","S"),sep="")
    elif f("W","S","W"):
        print(*f("W","S","W"),sep="")
    elif f("W","W","S"):
        print(*f("W","W","S"),sep="")
    elif f("S","W","W"):
        print(*f("S","W","W"),sep="")
    else:
        print(-1)
else:
    if f("W","W","W"):
        print(*f("W","W","W"),sep="")
    elif f("W","S","S"):
        print(*f("W","S","S"),sep="")
    elif f("S","S","W"):
        print(*f("S","S","W"),sep="")
    elif f("S","W","S"):
        print(*f("S","W","S"),sep="")
    else:
        print(-1)