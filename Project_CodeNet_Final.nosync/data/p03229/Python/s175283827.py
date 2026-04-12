n = int(input())
a = [int(input()) for _ in range(n)]
a.sort(reverse = True)
b = [0] * n
l = n // 2 - 1
for i in range(l):
    b[i] = 2
b[l] = 1
if n % 2 == 1:
    b[l + 1] = 1
else:
    b[l + 1] = -1
for i in range(l + 2, n):
    b[i] = -2
ans1, ans2 = 0, 0
for i in range(n):
    ans1 += (a[i] * b[i])
    ans2 += (-1 * a[i] * b[n - i - 1])
print(max(ans1, ans2))