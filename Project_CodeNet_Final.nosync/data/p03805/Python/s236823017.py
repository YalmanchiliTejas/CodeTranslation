import itertools

N, M = map(int, input().split())
array = [" -> ".join(input().split()) for _ in range(M)]

permutation_list = itertools.permutations([x + 1 for x in range(N)])

count = 0
flg = True
for data in permutation_list:
    # print(data)
    if data[0] != 1:
        continue
    for i in range(1, len(data)):
        param = "{} -> {}".format(data[i - 1], data[i])
        param2 = "{} -> {}".format(data[i], data[i - 1])
        if array.count(param) > 0 or array.count(param2) > 0:
            pass
            # print("あった " + param)
        else:
            # print("なかった NG")
            flg = False
            break
    if flg is False:
        flg = True
        continue
    # print(data)
    count += 1

print(count)
