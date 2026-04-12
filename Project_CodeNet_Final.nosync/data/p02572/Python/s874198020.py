n = int(input())
A = [int(x) for x in input().split()]
l = []

a = 0
for i in reversed(A):
    a += i
    l.append(a)
l.pop(n-1)
ans = 0

l.reverse()
for i in range(n-1):
    ans += (A[i]*l[i])
print(ans%(10**9+7))
