n = int(input())
li = list(map(int,input().split()))
ans = 0
h = li[0]
for t in li:
    if t >= h:
        ans +=1
        h =t
print(ans)