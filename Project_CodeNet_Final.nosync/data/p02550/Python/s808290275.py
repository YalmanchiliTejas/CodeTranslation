N, X, M = map(int, input().split())
C = X
F = {X}
S = 0
cnt = 0
loop = 0
loop_S = 0
while cnt < N:
    S += C
    cnt += 1
    C *= C
    C %= M
    if C in F:
        break
    F.add(C)
st = C
L = 0
if cnt < N:
    val = (st * st) % M
    loop += 1
    loop_S = st
    while val != st:
        loop_S += val
        loop += 1
        val *= val
        val %= M
    ccnt = N - ((N-cnt)//loop)*loop - cnt
    res = 0
    val = st
    while ccnt > 0:
        res += val
        val *= val
        val %= M
        ccnt -= 1
    print(S+loop_S*((N-cnt)//loop)+res)
else:
    print(S)