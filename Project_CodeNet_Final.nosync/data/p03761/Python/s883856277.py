n = int(input())
l = [list(list(input())) for _ in range(n)]

l = sorted(l, key = len)

x = []
for i in range(len(l[0])):
    y = 0
    for j in range(n):
        if l[0][i] in l[j]:
            y +=1
            if y == n:
                x.append(l[0][i])
                for k in range(1, n):
                    l[k].remove(l[0][i])

print(''.join(sorted(x)))