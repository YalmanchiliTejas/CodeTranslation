n = int(input())
a = list(map(int,input().split()))
inf = 10 ** 9 + 7

S = sum(a)
S2 = 0

for i in a:
    S2 += i * i

print((S*S - S2)//2 % inf)