N = int(input())
s = input()
def solve(ans):
    for i in range(2,N):
        if ans[i-2]=='S' and ans[i-1]=='S':
            if s[i-1]=='o':
                ans += 'S'
            else:
                ans += 'W'
        elif ans[i-2]=='S' and ans[i-1]=='W':
            if s[i-1]=='o':
                ans += 'W'
            else:
                ans += 'S'
        elif ans[i-2]=='W' and ans[i-1]=='S':
            if s[i-1]=='o':
                ans += 'W'
            else:
                ans += 'S'
        else:
            if s[i-1]=='o':
                ans += 'S'
            else:
                ans += 'W'
    if (ans[0]=='S' and s[0]=='o') or (ans[0]=='W' and s[0]=='x'):
        if ans[-1]!=ans[1]:
            return
    elif (ans[0]=='S' and s[0]=='x') or (ans[0]=='W' and s[0]=='o'):
        if ans[-1]==ans[1]:
            return
    if (ans[-1]=='S' and s[-1]=='o') or (ans[-1]=='W' and s[-1]=='x'):
        if ans[-2]!=ans[0]:
            return
    elif (ans[-1]=='S' and s[-1]=='x') or (ans[-1]=='W' and s[-1]=='o'):
        if ans[-2]==ans[0]:
            return
    return ans

C = ['SS','SW','WS','WW']

for c in C:
    if solve(c):
        print(solve(c))
        break
else:
    print(-1)