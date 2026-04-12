if __name__ == '__main__':
    
    ans = []
    ans2 = []
    
    while True:
        n,m = map(int,input().split(","))
        
        if n == 0 and m == 0:
            break
        
        if m not in ans:
            ans.append(m)
        ans2.append((n,m))
        
        ans.sort()
        ans.reverse()
        
    while True:
        try:
            x = int(input())
            y = ans2[x-1][1]
            ind = ans.index(y) + 1

            print(ind)
        except EOFError:
            break

