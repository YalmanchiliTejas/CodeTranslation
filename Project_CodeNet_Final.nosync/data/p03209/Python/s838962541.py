n, x = map(int, input().split())

def dp(a, b):
    if a == 1:
        if 1 <= b <= 4:
            return b-1
        else:
            return 3
    elif b == 1:
        return 0
    elif 1 < b < 2**(a+1)-1:
        return dp(a-1, b-1)
    elif b == 2**(a+1)-1:
        return dp(a-1, 2**(a+1)-3) + 1
    elif 2**(a+1)-1 < b < 2**(a+2)-3:
        return dp(a-1, 2**(a+1)-3) + 1 + dp(a-1, b+1-2**(a+1))
    elif b == 2**(a+2)-3:
        return dp(a-1, 2**(a+1)-3) * 2 + 1
    
print(dp(n, x))