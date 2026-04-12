N, X = map(int, input().split())

def get_size(level):
    return (1 << (level+2)) - 3

def get_patty(level):
    return (1 << (level+1)) - 1

ans = 0
while X > 0:
    if get_size(N) > X:
        X -= 1
        N -= 1
    else:
        X -= get_size(N)
        ans += get_patty(N)
        if X > 0:
            ans += 1
            X -= 1
print(ans)
