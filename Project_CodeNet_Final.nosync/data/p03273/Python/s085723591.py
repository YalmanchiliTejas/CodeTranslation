h,w = (int(x) for x in input().split())
ab = []
counth = 0
for _ in range(h):
    a = input()
    a = list(a)
    if '#' not in a:
        counth += 1
        continue
    ab.append(a)
countw =[] 
for i in range(w):
    memo = 0
    #print(12121)
    for j in range(h-counth):
        if ab[j][i] == '.':
            memo += 1
            if memo == h-counth:
                countw.append(i)
countw.sort(reverse=True)
for j in countw:
    for i in range(h-counth):
        del ab[i][j]

for i in range(h-counth):
    print(''.join(ab[i]))