def solve(n, h_list):
    m = 0
    vc = 0
    for h in h_list:
        if m <= h:
            vc += 1
            m = h
    print(vc)

n = int(input())
h_list = map(int,input().split())    
solve(n, h_list)