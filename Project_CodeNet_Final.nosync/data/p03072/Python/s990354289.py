input()
a = list(map(int, input().split()))
ret = 0
for i, h in enumerate(a):
    ret += max(a[:i + 1]) == h
print(ret)