N,X,M = map(int, input().split())

ans = X
N -= 1
prev = X
used = [0]*M

while N:
    new = pow(prev, 2, M)
    if used[new] == 1:
        cnt = 1
        num = new
        while new != prev:
            num += pow(new, 2, M)
            new = pow(new, 2, M)
            cnt += 1
        ans += (N//cnt)*num
        N %= cnt
        break
    used[new] = 1
    ans += new
    prev = new
    N -= 1

while N:
    new = pow(prev, 2, M)
    ans += new
    prev = new
    N -= 1
print(ans)