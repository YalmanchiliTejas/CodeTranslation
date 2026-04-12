import copy
class Node:
    def __init__(self):
        self.adjacentnode=[]

def search(lista,nodet):
    global count
    global n
    if len(lista)==n:
            count+=1
            return True
    for a in nodet[lista[-1]].adjacentnode:
        if a not in lista:
                newlist=copy.copy(lista)
                newlist.append(a)
                search(newlist,nodet)

n,m=map(int,input().split()) #n is node,m is edge 
count=0
listsrch=[0]
nodelist=[Node() for a in range(n)]
for t in range(m):
    a,b=map(int,input().split())
    nodelist[a-1].adjacentnode.append(b-1)
    nodelist[b-1].adjacentnode.append(a-1)
search(listsrch,nodelist)
print(count)