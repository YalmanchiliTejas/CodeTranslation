def solve():
    N = int(input())
    H = [int(s) for s in input().split() if s]
    max_height = 1
    count = 0
    for h in H:
        if h >= max_height:
            count += 1
            max_height = h
    print(count)
    
solve()