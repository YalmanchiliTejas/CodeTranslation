import collections
n = int(input())
S = []
A = {}
for i in range(n):
    s = input()
    if i == 0:
        for j in s:
            if j in A: A[j] += 1
            else: A[j] = 1
    else:
        B = {}
        for j in s:
            if j in B: B[j] += 1
            else: B[j] = 1
        for j in A:
            if j in B:
                A[j] = min(A[j], B[j])
            else:
                A[j] = 0
ans = ""
for i in A:
    if A[i] > 0:
        ans += i*A[i]
ans = list(ans)
ans.sort()
print("".join(ans))