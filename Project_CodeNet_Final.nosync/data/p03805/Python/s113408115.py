#abc 054 C
n,m = map(int, input().split()) #  N頂点 ,M辺
connect = [[] for i in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    connect[a-1].append(b -1)
    connect[b -1].append(a -1)
#print(connect)
import itertools 

state = list(itertools.permutations(list(range(n)) ,n ))
def abc054c(i):#
    counter = 1
    if i[0] != 0:
        return 0
    for j,k  in enumerate(i):
        if j == n -1:
            pass
        elif i[j +1] in connect[k]:
            pass
        else:
            counter = 0
            break
    return counter
total = 0
for  i in state:
    total += abc054c(i)
    
print(total)    
    