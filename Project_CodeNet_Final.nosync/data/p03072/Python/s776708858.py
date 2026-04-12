def p_b():
    n = int(input())
    *H, = map(int, input().split())
    c = 0
    ans = 0
    for h in H:
        if c <= h:
            c = h
            ans += 1
    print(ans)

    
p_b()