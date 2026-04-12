def putty():
    N,X = map(int,input().split())
    ans = 0

    for i in range(0,N+1)[::-1]:
        width = 2**(i+2)-3
        if X <= i:   return ans
        elif X >= width - i:    return ans + 2**(i+1)-1
        else:
            mid = (width + 1) // 2
            if X == mid:    return ans + 2**(i)
            elif X < mid:   X -= 1 
            else:
                X -= 2**(i+1)-3 + 2 
                ans += 2**(i)

print(putty())