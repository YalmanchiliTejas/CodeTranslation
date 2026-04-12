N = int(input())
H = list(map(int, input().split()))

first = H[0]
ret = 0
for it in H:
    if it >= first:
        ret += 1
        first = it
print(ret)