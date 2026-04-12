from itertools import permutations

def readinput():
    n,m=list(map(int,input().split()))
    nList=[]
    for _ in range(n+1):
        nList.append([])
    for _ in range(m):
        a,b=list(map(int,input().split()))
        nList[a].append(b)
        nList[b].append(a)
    
    return n,m,nList

def main(n,m,nList):
    permlist = permutations(range(2,n+1))
    count=0
    for perm in permlist:
        current=1
        for i in range(n-1):
            next=perm[i]
            if not next in nList[current]:
                break
            current=next
        else:
            count+=1
    return count

if __name__=='__main__':
    n,m,nList=readinput()
    ans=main(n,m,nList)
    print(ans)
