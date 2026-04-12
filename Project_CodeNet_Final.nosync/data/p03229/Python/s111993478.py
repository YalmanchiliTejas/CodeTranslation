N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
min = 1
max = N-1
ans = [0 for _ in range(2*N+10)]
ans[len(ans)//2] = A[0]
l = len(ans) // 2
r = l
for i in range(1, N):
    left = False
    minS = False
    maxx = -1
    if abs(ans[l]-A[min]) > maxx:
        left = True
        minS = True
        maxx = abs(ans[l]-A[min])
    if abs(ans[l]-A[max]) > maxx:
        left = True
        minS = False
        maxx = abs(ans[l]-A[max])
    if abs(ans[r]-A[min]) > maxx:
        left = False
        minS = True
        maxx = abs(ans[r]-A[min])
    if abs(ans[r]-A[max]) > maxx:
        left = False
        minS = False
        maxx = abs(ans[r]-A[max])

    if left and minS:
        l -= 1
        ans[l] = A[min]
        min += 1
    elif left and not minS:
        l -= 1
        ans[l] = A[max]
        max -= 1
    elif not left and minS:
        r += 1
        ans[r] = A[min]
        min += 1
    else:
        r += 1
        ans[r] = A[max]
        max -= 1
an = 0
for i in range(l+1, r+1):
    an += abs(ans[i]-ans[i-1])
#print(ans)
print(an)
