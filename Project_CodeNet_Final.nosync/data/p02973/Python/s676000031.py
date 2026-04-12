N = int(input())
A = [int(input()) for _ in [0]*N]
B = [A[0]]
ans = 1

for a in A[1:]:
    l = 0
    r = ans - 1
    if B[0]<a:r=0
    while l+1<r:
        i = (l+r)//2
        if B[i] < a:
            r = i
        else:
            l = i
    if B[r]<a:B[r] = a
    else:
        B.append(a)
        ans += 1
print(ans)