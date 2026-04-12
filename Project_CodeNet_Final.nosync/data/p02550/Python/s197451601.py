import sys
input = sys.stdin.readline

def main():
    n, x, m = map(int, input().split())
    cycle = [False]*m
    next_list = [-1]*m
    cycle[x] = True
    
    now = x
    count = 1
    for i in range(m):
        nex = pow(now, 2, m)
        if count == n:
            break
        if cycle[nex]:
            next_list[now] = nex
            break
        next_list[now] = nex
        cycle[nex] = True
        now = nex
        count += 1
    
    ans = 0
    if count == n:
        for i in range(m):
            if cycle[i]:
                ans += i
        
    else:
        judge = x
        while judge != now:
            ans += judge
            judge = next_list[judge]
            n -= 1
        
        key = judge
        judge = next_list[judge]

        count = 1
        while judge != now:
            key += judge
            judge = next_list[judge]
            count += 1
        
        ans += n//count * key
        n %= count
        while n > 0:
            n -= 1
            ans += judge
            judge = next_list[judge]
    

        

    print(ans)

    
    
    
    
if __name__ == "__main__":
    main()
