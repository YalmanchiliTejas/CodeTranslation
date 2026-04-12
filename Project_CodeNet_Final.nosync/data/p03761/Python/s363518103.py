import copy

n = int(input())
S = list([list(input()) for _ in range(n)])

strlist=[]

B=copy.deepcopy(S)

for s1 in S:
    for moji in s1:
        c=False
        for s2 in B:
            if moji not in s2:
                c=False
                break
            else: c=True
        if c:
            strlist.append(moji)
            [B[i].remove(moji) for i in range(n)]
strlist.sort()
print(''.join(strlist))
            