from sys import setrecursionlimit
setrecursionlimit(4100000)
n, m = map(int, input().split())
P = [[] for i in range(n)]   #Pass
for i in range(m):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1  
    P[a].append(b)
    P[b].append(a)
#print(P)

c = 0   #cursol
R = [0 for i in range(n)]  #Record
tm = 1  #time

def all_search_dfs(c:int, tm:int, R:list):
    if R[c] == 0:
        R[c] = 1
        if  tm < n:
            return point_calculate(c, tm, R)
        elif tm == n:
            return 1
        else:
            return 0
    else:
        return 0

def point_calculate(c:int, tm:int, R:list):
    #print('c = ', c)
    p = 0
    #print('check = ', P[c])
    for i in range(len(P[c])):
        R2 = R[:]
        #print('before = ', R2)
        tmp = all_search_dfs(P[c][i], tm + 1, R2)
        #print('after = ', R2)
        #print('tmp = ', tmp)
        p += tmp
        #print('p = ', p)
    return p

print(all_search_dfs(c, tm, R))