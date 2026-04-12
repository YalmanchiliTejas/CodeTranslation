N,X = map(int,input().split())
ans = 0
while X != 1 and X != 2**(N+1)-1 and X != 2**(N+2)-3:
    if 1 < X < 2**(N+1)-1:
        X -= 1
        N -= 1
    else:
        ans += 2**N
        X -= 2**(N+1)-1
        N -= 1
if X == 2**(N+1)-1:
    ans += 2**N
elif X == 1:
    ans += 0
else:
    ans += 2**(N+1)-1
print(ans)
