N = int(input())
A = list(int(x) for x in input().split())
B = [0]
a = len(A)
sa = sorted(A)
su = 0
p = 10**9+7

for i in range(a):
    B.append(B[i] + sa[i])

for j in range(a):
    su += sa[j]*B[j]

print(su%p)