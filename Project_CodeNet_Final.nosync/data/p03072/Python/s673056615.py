from sys import stdin
n = int(stdin.readline().rstrip())
h = [int(x) for x in stdin.readline().rstrip().split()]
ans = 1
tmp = h[0]
for i in range(n - 1):
    ans += 1 if tmp <= h[i + 1] else 0
    tmp = max(tmp, h[i + 1])
print("{}".format(ans))