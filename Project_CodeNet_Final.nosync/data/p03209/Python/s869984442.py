def p_count(a, b):
    global l
    if b <= 0:
        return 0
    if a <= 0:
        return 1
    else:
        if b <= int(l[a][1]/2):
            return p_count(a-1, b-1)
        else:
            c = b - int(l[a][1]/2) - 1
            return l[a-1][0] + 1 + p_count(a-1, c)

l=list([[1,1]])
n,x = (int(i) for i in input().split())

for i in range(n):
    tmp = [(l[i][0]*2 + 1), (l[i][1]*2 + 3)]
    l.append(tmp)

print(p_count(n,x))