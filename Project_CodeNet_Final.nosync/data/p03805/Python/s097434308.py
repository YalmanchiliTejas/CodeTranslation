n,m = map(int,input().split())
vector = []
for i in range(m):
    a,b = map(int,input().split())
    vector.append([a,b])
    vector.append([b,a])
global kotae
kotae = 0
route =  [1]

def idou(route,vector):
    global kotae
    if len(route) == n:
        kotae += 1
        return 0
    for vec in vector:
        if vec[0] == route[-1] and vec[1] not in route:
            route.append(vec[1])
            idou(route,vector)
            route.remove(vec[1])
    return 0
    

idou(route,vector)
 
          
print(kotae)