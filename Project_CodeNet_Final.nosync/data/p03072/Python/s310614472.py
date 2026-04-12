N = input()
l = input().split()


result = 0

for i in range(len(l)):
    flg = 0

    if i == 0:
        result = 1
    else:
        for j in range(0, i):
            if int(l[i]) < int(l[j]):
                flg = 1

        if flg == 0:
            result = result + 1

if len(l) <= 20:
    print(result)
