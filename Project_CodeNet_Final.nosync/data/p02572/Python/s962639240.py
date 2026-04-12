n = input()
vals = list(map(int, input().split()))
s = sum(vals)
ret = 0
for i, val in enumerate(vals):
    ret += val * (s - val)

mod = 10 ** 9 + 7
print(int(ret//2) % mod)