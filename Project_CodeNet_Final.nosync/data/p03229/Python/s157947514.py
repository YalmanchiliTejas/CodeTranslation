n = int(input())
a_ls = []
for i in range(n):
    a_ls.append(int(input()))
a_ls.sort()
flg = n % 2 == 1
if flg:
    first = a_ls[:n//2]
    center = a_ls[n//2]
    second = a_ls[n//2 + 1:] + [center]
    best = 0
    for ind in range(n//2):
        best += abs(second[ind] - first[ind]) + abs(second[ind + 1] - first[ind])
    center = a_ls[n // 2]
    first = [center] + a_ls[:n // 2]
    second = a_ls[n // 2 + 1:]
    score = 0
    for ind in range(n // 2):
        score += abs(second[ind] - first[ind]) + abs(second[ind] - first[ind+1])
    if best < score:
        best = score
else:
    first = a_ls[:n // 2]
    second = a_ls[n // 2:]
    best = 0
    for ind, (i, j) in enumerate(zip(first, second)):
        if ind > 0:
            best += abs(j - last_i)
        best += abs(j - i)
        last_i = i
print(best)