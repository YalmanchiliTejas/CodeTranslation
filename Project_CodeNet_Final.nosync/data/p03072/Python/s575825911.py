def is_seeable(H):
    if len(H) == 1:
        return True
    for h in H[:-1]:
        if h > H[-1]:
            return False
    return True

N = int(input())
H = list(map(int, input().split()))

ans = 0
for i in range(len(H)):
    if is_seeable(H[:i+1]):
        ans = ans + 1
print(ans)
