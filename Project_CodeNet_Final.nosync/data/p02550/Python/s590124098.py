def main():
    n,x,m = map(int,input().split())
    
    #Compute i^2%m
    rem = [(i**2)%m for i in range(m)]

    #Find the cycle and its sum in n
    visited = [False for i in range(m)]
    idx = x
    s = x
    d = 1

    while not visited[idx]:
        visited[idx] = True
        s += rem[idx]
        idx = rem[idx]
        d += 1
        #print(s,idx,d)

    newsum = x
    newidx = x
    newd = 1
    while newidx!=idx:
        newsum += rem[newidx]
        newd += 1
        newidx = rem[newidx]

    #Adds newsum until it gets to idx, until n=newd
    #Cycles with sum s-newsum taking d moves
    d = d - newd
    s = s - newsum

    ans = x
    ansn = 1
    if newd<n:
        ans = newsum
        ansn = newd
    if ansn+d<=n:
        ans += s*((n-ansn)//d)
        ansn += ((n-ansn)//d) * d    
    #print(ans)
    while ansn<n:
        ansn += 1
        ans += rem[idx]
        idx = rem[idx]

    print(ans)
    #print(rem,newsum,newd,s,d)


if __name__=="__main__":
    main()