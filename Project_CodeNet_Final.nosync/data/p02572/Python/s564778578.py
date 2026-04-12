N = int(input())
A = list(map(int,input().split()))
res = 0
S = sum(A)
for a in A:
    res += a * (S - a)
    S = (S - a)
print(res % 1000000007)