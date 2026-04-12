import sys
def input():
    return sys.stdin.readline()[:-1]

n=int(input())
s=input()
tmp=["SS","WW","SW","WS"]
for j in range(4):
    ans=tmp[j]
    for i in range(n-1):
        if ans[i+1]=="S":
            if s[i+1]=="o":
                if ans[i]=="S":
                    ans+="S"
                else:
                    ans+="W"
            else:
                if ans[i]=="S":
                    ans+="W"
                else:
                    ans+="S"
        else:
            if s[i+1]=="o":
                if ans[i]=="S":
                    ans+="W"
                else:
                    ans+="S"
            else:
                if ans[i]=="S":
                    ans+="S"
                else:
                    ans+="W"
    if ans[0]==ans[-1]:
        if s[0]=="o":
            if ans[0]=="S" and ans[1]==ans[-2]:
                print(ans[:-1])
                quit()
            if ans[0]=="W" and ans[1]!=ans[-2]:
                print(ans[:-1])
                quit()
        else:
            if ans[0]=="S" and ans[1]!=ans[-2]:
                print(ans[:-1])
                quit()
            if ans[0]=="W" and ans[1]==ans[-2]:
                print(ans[:-1])
                quit()
print(-1)