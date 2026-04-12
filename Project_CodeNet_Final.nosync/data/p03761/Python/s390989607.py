
n = int(input())
dic = {}
flag = True

for i in range(n):

    S = input()

    #print (dic)

    if i == 0:

        for j in S:

            if j in dic:
                dic[j] += 1
            else:
                dic[j] = 1

    sdic = {}

    for j in S:

        if j in sdic:
            sdic[j] += 1
        else:
            sdic[j] = 1

    cdic = dic.copy()

    for j in cdic:

        if j not in sdic:

            del dic[j]

        else:

            dic[j] = min(dic[j],sdic[j])

lis = []

for i in dic:

    lis += [i] * dic[i]

lis.sort()

print ( "".join(lis) )
