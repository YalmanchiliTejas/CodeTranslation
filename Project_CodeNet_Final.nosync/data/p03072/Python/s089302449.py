n = int(input())
v = list(map(int,input().split(' ')))

tmp = v[0]
ans = 1
for i in range(1,n):
        if v[i] >= tmp:
            ans+=1
            tmp = v[i]
print(ans)