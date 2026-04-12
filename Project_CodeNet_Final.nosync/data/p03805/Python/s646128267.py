import itertools

[n,m] = [int(x) for x in input().split()]
data = [[int(x) for x in input().split()] for _ in range(m)]

total = 0
for x in itertools.permutations(range(2,n+1)):
    
    route = [1,]+list(x)
    
    for x in range(len(route)-1):
        flg = False
        
        for y in data:
            if {route[x],route[x+1]} == set(y):
                flg = True
                break
                
        if flg == False:
            break
            
    else:
        total += 1
        
print(total)
        