X,Y,Z = map(int,input().split())
ans = 0
total = ans * Y + (ans+1) * Z
while(total < X):
    ans += 1
    total = ans * Y + (ans+1) * Z
if(total == X):
    print(ans)
else:
    print(ans - 1)