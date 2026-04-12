n,m = map(int, raw_input().split())
mat = []
for i in xrange(n):
    mat.append(list(raw_input()))

l = [[0 for i in xrange(m)] for j in xrange(n)]

for i in xrange(n):
    flag = 0
    for j in xrange(1,m):
        if mat[i][j] != mat[i][0]:
            flag = 1
    if flag or mat[i][0] != '.':
        for j in xrange(m):
            l[i][j] = 1


for i in xrange(m):
    flag = 0
    for j in xrange(1,n):
        if mat[j][i] != mat[0][i]:
            flag = 1

    if not flag and mat[0][i] == '.':
        for j in xrange(n):
            l[j][i] = 0



for i in xrange(n):
    s = ''
    for j in xrange(m):
        if l[i][j]:
            s += mat[i][j]
    if s != '':
        print s
