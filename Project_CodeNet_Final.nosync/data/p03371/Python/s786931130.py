#W, H, x, y, r = map(int, input().split())
def main():
    a, b, c, x, y = map(int, input().split())

    min_sum = 100000 * 5000 + 100000 * 5000 + 200000 * 5000

    if a == c and b == c :
        min_sum = a * x + b * y
    elif a  < c and b < c  or a  == c and b  < c or a < c and b  == c :
        min_sum = a * x + b * y
    elif a  > c and b  > c or a  == c and b  > c or a  > c and b  == c  :
        if x >= y :
            min_sum = y * 2 * c
            if a > c * 2:
                min_sum = min_sum + (x - y) * c * 2
            else:
                min_sum = min_sum + (x - y ) * a
        else:
            min_sum = x * 2 * c
            if b > c * 2:
                min_sum = min_sum + (y - x) * c * 2
            else:
                min_sum = min_sum + (y - x ) * b
    elif a < c and b > c:
        if c - a > b - c : #むだ
            min_sum = a * x + b * y
        else:
            if x >= y :
                min_sum = (x-y)* a + y * c * 2
            else:
                min_sum = (y-x)* b + x * c * 2
    elif a > c and b < c:
        if c - b > a - c   : #むだ
            min_sum = a * x + b * y
        else:
            if x >= y :
                min_sum = (x-y)* a + y * c * 2
            else:
                min_sum = (y-x)* b + x * c * 2


    else:
        for i in range(0, x+1):
            for j in range(0, y+1):
                if min_sum > a * i + b * j + max(x-i, y-j) * c * 2:
                    min_sum =a * i + b * j + max(x-i, y-j) * c * 2

    print(min_sum)
main()
# if a >= c and b <= c :
#     sum = x * c * 2
#     if x <= y :
#         sum = sum + ( y - x ) * b
# else:
#     sum = y * c * 2
#     if x >= y :
#         sum = sum + ( x - y ) * a


# if b > c * 2 :
    #     b_price = c
    #
    # input_array_list = []
    #
    # while True:
    #     input_array = input().split()
    #     if input_array[0] == "0" and input_array[1] == "0":
    #         break
    #     else:
    #         input_array_list.append(input_array)
    #
    # for item in input_array_list:
    #     n = int(item[0])
    #     k_sum = int(item[1])
    #
    #     count = 0
    #     for i in range(1,n + 1- 2):
    #         for j in range(i+1, n + 1 - 1):
    #             for k in range (j+1, n+ 1):
    #                 if i + j + k == k_sum :
    #                     count = count + 1
    #     print(count)

    #
    # for item in input_array_list:
    #     if item[1] == "+":
    #         print(str(int(item[0])+int(item[2])))
    #     elif item[1] =="-":
    #         print(str(int(item[0])-int(item[2])))
    #     elif item[1] == "/":
    #         print(str(int(item[0])//int(item[2])))
    #     elif item[1] == "*":
    #         print(str(int(item[0])*int(item[2])))
    #

# import sympy as sp

# input_list = []
# a,b,c = map(int, input().split())
# divisors = sp.divisors(c)
#
# count = 0
#
# for divisor in divisors:
#     if a <= divisor and divisor <= b:
#         count = count + 1
# print(count)
#
# while True:
#     pair_str = input().split()
#     pair_int = [int(s) for s in pair_str]
#     if pair_int[0] == 0 and pair_int[1] == 0 :
#         break
#     else:
#         input_list.append(pair_int)
#
# for pair_int in input_list:
#     if pair_int[0] <= pair_int[1]:
#         print("{} {}".format(pair_int[0], pair_int[1]))
#     else:
#         print("{} {}".format(pair_int[1], pair_int[0]))

#for i in range(10000):
#    print("Hello World")
#a = input().split()
#a_int = [int(s) for s in a]
#a_sorted = sorted(a_int)
#print(' '.join(map(str, a_sorted)))
