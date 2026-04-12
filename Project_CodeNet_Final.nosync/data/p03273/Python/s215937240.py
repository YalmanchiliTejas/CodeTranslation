H, W = map(int, input().split())
a = []
for i in range(H):
    b = input()
    count = b.count('.')
    if count == W:
        continue
    else:
        a += [list(map(str, b))]

num = len(a)
val = []
for i in range(W):
    for j in range(num):
        if a[j][i] == '.':
            if j == num-1:
                val.append(i)
            else:
                continue
        else:
            break
for i in reversed(val):
    for j in range(num):
        del a[j][i]
for i in range(len(a)):
    print(''.join(a[i]))

    
