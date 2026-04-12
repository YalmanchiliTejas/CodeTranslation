d={"o":1,"x":-1}
w={"S":1,"W":-1}
n={1:"S",-1:"W"}
N=int(raw_input())
s=raw_input()
s+=s[0]
def ans(a):
    for i in range(1,N+1):
        a+=n[w[a[i]]*w[a[i-1]]*d[s[i]]]
    if a[:2]==a[-2:]:
        return a[:-2]
    else:
        return []
for ini in ["SS","SW","WS","WW"]:
    a=ans(ini)
    if a:
        print a
        break
else:
    print "-1"