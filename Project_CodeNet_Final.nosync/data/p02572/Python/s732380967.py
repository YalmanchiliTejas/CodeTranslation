n = int(input())
a = list(map(int, input().split()))
b = []
su = 0

la = len(a)
ele = a[la - 1]

for i in range(1, len(a) - 1):
    ele = ele + a[la - i - 1]
    b.append(ele)

lb = len(b)

for j in range(len(a) - 2):
    su = su + a[j] * b[lb - j - 1]

su = su + a[len(a) - 1] * a[len(a) - 2]

print(su % (10**9 + 7))