import collections
n = int(input())
S = []
A = collections.Counter(input())
for i in range(n-1):
    B = collections.Counter(input())
    A &= B
ans = ""
for i in A:
    if A[i] > 0:
        ans += i*A[i]
ans = list(ans)
ans.sort()
print("".join(ans))