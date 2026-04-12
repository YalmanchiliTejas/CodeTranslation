n = int(input())
hl = list(map(int,input().split()))	

ans = 0
tmp = 0
for h in hl:
    if h >= tmp:
        tmp = h
        ans +=1 

print(ans)