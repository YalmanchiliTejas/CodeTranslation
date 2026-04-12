import sys
input=sys.stdin.readline
n=int(input())
s=input().rstrip()
start=['SS','SW','WS','WW']
import sys
for k in start:
    ans=[k[0],k[1]]
    for i in range(2,n):
        if (ans[i-2]=='S' and ans[i-1]=='S' and s[i-1]=='o') or (ans[i-2]=='S' and ans[i-1]=='W' and s[i-1]=='x') or (ans[i-2]=='W' and ans[i-1]=='S' and s[i-1]=='x') or (ans[i-2]=='W' and ans[i-1]=='W' and s[i-1]=='o'):
            ans.append('S')
        else:
            ans.append('W')
    if (s[0]=='o' and ans[0]=='S') or (s[0]=='x' and ans[0]=='W'):
        if ans[1]==ans[n-1]:
            pass
        else:
            continue
    else:
        if ans[1]==ans[n-1]:
            continue
    if (s[n-1]=='o' and ans[n-1]=='S') or (s[n-1]=='x' and ans[n-1]=='W'):
        if ans[0]==ans[n-2]:
            pass
        else:
            continue
    else:
        if ans[0]==ans[n-2]:
            continue
    for i in ans:
        print(i,end='')
    sys.exit()
print(-1)
    


