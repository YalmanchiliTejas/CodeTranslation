n=int(input())
s=input()
s=s+s[0]
for a,b in [(0,0),(0,1),(1,0),(1,1)]:
    ans=[a,b]+[1]*n
    for i in range(2,n+2):
        ans[i]^=ans[i-2]^ans[i-1]^(s[i-1]=='o')
    if ans[:2]==ans[-2:]:
        for i in range(n):
            print('SW'[ans[i]],end='')
        break
else:
    print(-1)