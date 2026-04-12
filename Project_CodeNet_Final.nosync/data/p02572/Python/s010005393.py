N = int(input())
A_list = list(map(int, input().split()))
MOD = 10**9+ 7

suma = sum(A_list)

res = 0
for a in A_list:
    suma -= a
    res += suma * a

print(res%MOD)
