[X,Y,Z] = list(map(int,input().split()))
ans = -1
for i in range(100010):
    L = Y*i+Z*(i+1)
    if L <= X:
        ans = i
print(ans)
