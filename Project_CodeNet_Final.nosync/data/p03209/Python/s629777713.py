a = []
p = []

def dfs (x,i,depth):

    if i <= 1:
        #print(x)
        if x == 0:
            return 0
        elif x == 1:
            return 1
        elif x == 2:
            return 2
        elif x >= 3:
            return 3
    else:
        #print(a[i],a[i]//2,x)
        if a[i]//2 < x  :
            x = x - a[i]//2 - 1
            #print("right>>>",p[i-1] + 1,x)
            return (p[i-1] + 1) + dfs(x,i-1,depth)
        elif a[i]//2 == x :
            #print("<<<mid>>>",1,x)
            return (1 + dfs(x-1,i-1,depth))
        else:
            #print("left<<<",0,x)
            if x - 1 <= 0:
                return 0
            else:
                return dfs(x-1,i-1,depth)

def ddff (i,depth):
    if i >= depth-1:
        return 'bpppb'
    else:
        return 'b' + ddff(i+1,depth) + 'p' + ddff(i+1,depth) + 'b'
 
n,x = map(int,input().split())

for i in range(n+1):
    p.append(2**(i+1)-1)
    b = 2**(i+1)-2
    a.append(p[i] + b)
#print(a,p)

r = dfs(x-1,n,n)
print(r)