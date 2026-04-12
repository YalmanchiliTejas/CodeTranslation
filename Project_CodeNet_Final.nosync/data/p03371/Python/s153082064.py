a,b,c,x,y = map(int,input().split())

C = c*2
ans = []
if C<a+b:
    if x>y:
        ans.append(C*x)
        ans.append(C*y+a*(x-y))
    else:
        ans.append(C*y)
        ans.append(C*x+b*(y-x))
else:
    ans.append(a*x+b*y)
print(min(ans))