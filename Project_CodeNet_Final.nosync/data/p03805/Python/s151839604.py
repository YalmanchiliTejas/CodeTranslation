import itertools

n,m = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(m)]

seq = list(range(2, n+1))
ptr = list(itertools.permutations(seq, n-1))

ans = 0
for i in ptr:
    flag2 = True
    for j in range(n-1):
        flag = False
        if j == 0:
            for a,b in ab:
                if (a,b) == (1,i[j]) or (a,b) == (i[j],1):
                    flag = True
                    break
        else:
            for a,b in ab:
                if (a,b) == (i[j], i[j-1]) or (a,b) == (i[j-1], i[j]):
                    flag = True
                    break
        if not flag:
            flag2 = False
            break
    if flag2:
        ans += 1

print(ans)
