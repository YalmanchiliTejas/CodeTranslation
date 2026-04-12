
N,M = map(int,input().split())
lis = []
path = ["1"]

for i in range(M):

    a,b = map(int,input().split())
    lis.append([a,b])

for i in range(N-1):

    i += 1

    npath = []

    for p in path:


        for j in lis:

            if j[0] == int(p[-1]) and str(j[1]) not in p:

                npath.append(p + str(j[1]))

            if j[1] == int(p[-1]) and str(j[0]) not in p:

                npath.append(p + str(j[0]))

    path = npath.copy()


print (len(path))
