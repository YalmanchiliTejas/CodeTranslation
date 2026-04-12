n = int(input())
a = [int(input()) for i in range(n)]

a.sort(reverse = True)


keisuu = [0]*n
for i in range(n-1):
    if i % 2 == 0:
        keisuu[i] += 1
        keisuu[i+1] -= 1
    else:
        keisuu[i] -= 1
        keisuu[i+1] += 1
ans = 0
keisuu.sort(reverse = True)
for i in range(n):
    ans += a[i] * keisuu[i]


keisuu = [0]*n
for i in range(n-1):
    if i % 2 == 1:
        keisuu[i] += 1
        keisuu[i+1] -= 1
    else:
        keisuu[i] -= 1
        keisuu[i+1] += 1
keisuu.sort(reverse = True)
ans1 = 0
for i in range(n):
    ans1 += a[i] * keisuu[i]

print(max(ans, ans1))
