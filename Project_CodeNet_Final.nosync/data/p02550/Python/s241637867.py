N,X,M = map(int,input().split())
cur = X
S = set([X])
while True:
    nA = cur**2 % M
    if nA in S:
        break
    S.add(nA)
    cur = nA
loop = [nA]
while True:
    ne = loop[-1]**2 % M
    if ne == nA:
        break
    loop.append(ne)
ll = len(loop)
sl = sum(loop)
ans = [X]
while True:
    ne = ans[-1]**2 % M
    if ne == nA:
        break
    ans.append(ne)
la = len(ans)
if N <= la:
    print(sum(ans[:N]))
else:
    loop_num = (N-la)//ll
    loop_head = (N-la) % ll
    print(sum(ans)+sl*loop_num+sum(loop[:loop_head]))