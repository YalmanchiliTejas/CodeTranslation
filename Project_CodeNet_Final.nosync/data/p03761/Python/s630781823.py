n = int(input())
ans = ""
S1 = input()
alp = {}

if n == 1:
    for x in sorted(S1):
        ans += x
    print(ans)   
else:
    for x in S1:
        if x not in alp.keys():
            alp[x] = 1
        else:
            alp[x] += 1
    for i in range(n-1):
        S = input()
        empty = []
        for x in alp.keys():
            n = S.count(x)
            if n == 0:
                empty.append(x)
            elif n < alp[x]:
                alp[x] = n
        for x in empty:
            del alp[x]
    for x in sorted(alp.keys()):
        for i in range(alp[x]):
            ans += x
    print(ans)