
def solve(n,k):
    for i in range(len(n)):
        if n[i] != 0:
            break
    n = n[i:]
    if n == []:
        return 0
    l = len(n)
    ans = 0
    # n-1桁からKこ取る
    tmp = 1
    for i in range(1, k+1):
        tmp = tmp*9*(l-i)
    for i in range(1, k+1):
        tmp = tmp // i
    ans += tmp

    # 最上位から1つ（最上位の数以外）とる。
    tmp = n[0]-1
    for i in range(1, k):
        tmp = tmp*9*(l-i)
    for i in range(1, k):
        tmp = tmp // i
    ans += tmp

    # 最上位からその数をとる。
    tmp = 0
    if k == 3:
        tmp += solve(n[1:],k-1)

    elif k == 2:
        for i in range(1, l):
            if n[i] != 0:
                tmp += n[i] + 9*(l-i-1)
                break
    else:
        tmp += 1
    ans += tmp
    return ans

n = list(map(int, input()))
k = int(input())

print(solve(n,k))
