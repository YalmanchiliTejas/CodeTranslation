N=int(input())
s=[c=="x" for c in input()]
ans = [0]*N
end = False
for c0 in (0,1):
    ans[0] = c0
    for cN in (0,1):
        ans[-1] = cN
        for i,c in enumerate(s[:-2]):
            ans[i+1] = ans[i-1] ^ (ans[i]^c)
        end = (ans[-1]==ans[-3]^(ans[-2]^s[-2])) and (ans[0]==ans[-2]^(ans[-1]^s[-1]))
        if end:break
    if end:break
if end:print("".join(["SW"[a] for a in ans]))
else:print(-1)