n = int(input())
ans = list(input())

for i in range(n-1):
    compare = list(input())
    res = []
    
    for j in ans:
        if j in compare:
            res.append(j)
            compare.remove(j)
            
    ans = res
    
print(*sorted(ans),sep="")