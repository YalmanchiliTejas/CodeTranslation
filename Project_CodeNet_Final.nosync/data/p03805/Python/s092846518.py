from itertools import permutations

def getval():
    n,m = map(int,input().split())
    g = [[] for i in range(n)]
    for i in range(m):
        a,b = map(int,input().split())
        g[a-1].append(b-1)
        g[b-1].append(a-1)
    return n,m,g

def main(n,m,g):
    ans = 0
    for p in permutations(range(n-1)):
        flag = True
        idx = 0
        for i in p:
            if not i+1 in g[idx]:
                flag = False
                break
            idx = i+1
        if flag:
            ans += 1
    print(ans)

if __name__=="__main__":
    n,m,g = getval()
    main(n,m,g)