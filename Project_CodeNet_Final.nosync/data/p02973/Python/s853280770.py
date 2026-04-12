n = int(input())
A = [int(input()) for i in range(n)]

Q = [-float("inf"), A[0]] + [float("inf")] * (n+1)
le = 2
for i in range(1, n):
    if Q[le-1] >= A[i]:
        Q[le] = A[i]
        le += 1
    else:
        l = 0
        r = le
        m = (l+r)//2
        while r-l > 1:
            if Q[m] >= A[i]:
                l = m
            else:
                r = m
            m = (l+r)//2
        Q[l+1] = A[i]
    # print(Q[:10])

print(le-1)