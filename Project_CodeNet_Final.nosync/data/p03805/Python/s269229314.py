n, m = map(int, input().split())
to = [[] for i in range(n)]


for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    to[a].append(b)
    to[b].append(a)

used = [False for i in range(n)]
perm = [0 for i in range(n)]
count = 0
#print(to)
def permutation(pos, last):
    global count
    if pos == last:
        #処理
        if perm[0] == 0:
            connect = False
            count_check = True
            #print(perm)
            for i in range(1, n):
                for j in to[perm[i - 1]]:
                    if perm[i] == j:
                        connect = True
                if not connect:
                    count_check = False
                    break
                else:
                    connect = False
            if count_check:
                count += 1
        else:
            return
    for i in range(last):
        if not used[i]:
            perm[pos] = i
            used[i] = True
            permutation(pos + 1, last)
            used[i] = False
    return


permutation(0, n)
print(count)
