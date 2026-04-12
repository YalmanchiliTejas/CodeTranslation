h,w = map(int,input().split())
A = [list(map(str,input())) for i in range(h)]
for k in range(max(h,w)):
    counter = 0
    for i in range(h):
        if '#' not in A[i-counter]:
            del(A[i-counter:i-counter+1])
            counter += 1
            h -= 1
        if i-counter >= h-1:
            break
    counter = 0
    B = [list(row) for row in zip(*A)]
    for j in range(w):
        if '#' not in B[j-counter]:
            del(B[j-counter:j-counter+1])
            counter += 1
            w -= 1
        if j-counter >= w-1:
            break
    A = [list(row) for row in zip(*B)]
for row in A:
    print(*row, sep='')