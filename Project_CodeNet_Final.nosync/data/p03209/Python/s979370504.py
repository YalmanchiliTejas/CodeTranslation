import sys

nx = input().split()
n = int(nx[0])
x = int(nx[1])
count = 0


lenlist = []
for i in range(n + 1):
    if i == 0:
        lenlist.append(1)
    else:
        lenlist.append(lenlist[-1] * 2 + 3)

pcountlist = []
for i in range(n + 1):
    if i == 0:
        pcountlist.append(1)
    else:
        pcountlist.append(pcountlist[-1] * 2 + 1)


def incr_count(nn, xx):
    global count

    if nn == 0:
        if xx > 0:
            count += 1
        return

    if xx <= 1:
        pass
    if 1 < xx and xx <= lenlist[nn] // 2:
        incr_count(nn - 1, xx - 1)
    if lenlist[nn] // 2 < xx:
        count += pcountlist[nn - 1]
        count += 1
        incr_count(nn - 1, xx - lenlist[nn] // 2 - 1)


incr_count(n, x)
print(count)
