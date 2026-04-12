import sys
def thk(n):
    return 2**(n+2)-3
def pt(n):
    return 2**(n+1)-1
def ban(n):
    return 2**(n+1)-2

N,X = map(int, input().split(' '))
ans = 0

while(True):
    if X == 0:
        break
    elif X == thk(N)//2+1:
        ans += pt(N-1)+1
        break
    elif X == thk(N):
        ans += 2*pt(N-1)+1
        break
    elif X > thk(N)//2+1:
        ans += pt(N-1)+1
        X -= thk(N)//2+1
        N -= 1
    else:
        X -= 1
        N -= 1

print(ans)