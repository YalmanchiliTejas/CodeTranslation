N = int(input())
A = [int(input()) for x in range(N)]
A.sort()

a = [1, -1]
listA = [0 for x in range(N)]
listB = [0 for x in range(N)]
for i in range(1, N):
    listA[i] += a[i % 2]
    # ビット反転　~
    listA[i - 1] += a[~(i % 2)]

    listB[i - 1] += a[i % 2]
    listB[i] += a[~(i % 2)]

listA.sort()
listB.sort()
listA = [x * y for (x, y) in zip(listA, A)]
listB = [x * y for (x, y) in zip(listB, A)]

ans = max(sum(listA), sum(listB))

print(ans)