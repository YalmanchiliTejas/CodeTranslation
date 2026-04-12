n = int(input())
n_list = [int(i) for i in input().split()]

s = sum(a**2 for a in n_list)
ans = sum(n_list) ** 2 - s

print((ans//2)%(10**9+7))