N = int(input())
A = list(map(int, input().split()))
ans = 1
for i in range(1, N):
    ok = True
    for j in range(i):
        if A[j] > A[i]:
            ok = False
    if ok:
        ans += 1

print (ans)