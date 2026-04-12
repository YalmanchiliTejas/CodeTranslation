n = int(input())
a = [0 for i in range(n)]
for i in range(n):
    a[i] = int(input())
a.sort()
ans_array = [0 for i in range(n)]
#p0 <= p1 >= p2...
coef_1 = [0 for i in range(n)]
coef_1[0] = -1
#p0 >= p1 <= p2 ...
coef_2 = [0 for i in range(n)]
coef_2[0] = 1
index = 0
ans = 0
if n % 2 == 1:
    coef_1[-1] = -1
    coef_2[-1] = 1
else:
    coef_1[-1] = 1
    coef_2[-1] = -1
for i in range(1,n-1):
    if i % 2 == 1:
        coef_1[i] = 2
        coef_2[i] = -2
    else:
        coef_1[i] = -2
        coef_2[i] = 2
coef_2.sort()
coef_1.sort()
ans1 = 0
ans2 = 0
for i in range(n):
    ans1 += coef_1[i]*a[i]
    ans2 += coef_2[i]*a[i]
print(max(ans1,ans2))