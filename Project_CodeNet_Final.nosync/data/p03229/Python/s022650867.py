import itertools
n=int(input())
int_list=[int(input()) for i in range(n)]

# max min

int_list.sort()

if n%2 == 0:
    big = int_list[int(n)//2+1:]
    mid = int_list[int(n)//2-1:int(n)//2+1]
    min = int_list[:int(n)//2-1]
    result = 0
    a = mid[1]
    b = mid[0]

    for i, (plus, minus) in enumerate(zip(big, min)):
        if i%2 == 0:
            result += abs(b-plus)
            result += abs(a-minus)
            a = minus
            b = plus
        else:
            result += abs(b-minus)
            result += abs(a-plus)
            a = plus
            b = minus

    result += abs(a-b)
    print(result)
else:
    result_1 = 0
    result_2 = 0
    big = int_list[int(n)//2+2:]
    mid = int_list[int(n)//2:int(n)//2+2]
    min = int_list[:int(n)//2]
    left = mid[1]
    right = mid[0]

    for plus, minus in itertools.zip_longest(big, min):
        result_1 += abs(left - minus)
        if plus != None:
            result_1 += abs(minus - plus)
            left = plus
        else:
            left = minus

    result_1 += abs(left - right)

    big = int_list[int(n)//2+1:]
    mid = int_list[int(n)//2-1:int(n)//2+1]
    min = int_list[:int(n)//2-1]
    left = mid[0]
    right = mid[1]
    for plus, minus in itertools.zip_longest(big, min):
        result_2 += abs(left - plus)
        if minus != None:
            result_2 += abs(minus - plus)
            left = minus
        else:
            left = plus

    result_2 += abs(left - right)

    print(max(result_1, result_2))