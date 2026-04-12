N = int(input())
A = [int(i) for i in input().split()]
MOD = 10 ** 9 + 7
S = 0
sq = 0

for a in A:
    S = (a + S) % (2*MOD)
    sq = (a ** 2 + sq) % (2*MOD)

ans = (S ** 2 - sq) % (2*MOD)

print(ans//2%MOD)

