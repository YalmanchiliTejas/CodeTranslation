def int_raw():
    return int(input())


def ss_raw():
    return raw_input().split()


def ints_raw():
    return list(map(int, ss_raw()))


def ceil(num):
    if int(str(num)[-1]) == 0:
        return num
    return num + 10 - int(str(num)[-1])


ans = 0
max_height = 0
N = int_raw()
inputs = ints_raw()
for i in range(N):
    if max_height <= inputs[i]:
        ans += 1
    max_height = max(max_height, inputs[i])
print(ans)
