n = int(input())
cnt = []
for _ in range(n):
    S = input()
    c = {chr(i):0 for i in range(97, 97+26)}
    for s in S:
        c[s] += 1
    cnt.append(c)

common = {chr(i):100 for i in range(97, 97+26)}
for c in cnt:
    for k, v in c.items():
        common[k] = min(common[k], v)

result = ''
for k, v in sorted(common.items()):
    result += k * v
print(result)

