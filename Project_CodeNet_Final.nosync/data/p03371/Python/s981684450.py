import copy
import math

# a = get_int()
def get_int():
    return int(input())
# a = get_string()
def get_string():
    return input()
# a_list = get_int_list()
def get_int_list():
    return [int(x) for x in input().split()]
# a_list = get_string_list():
def get_string_list():
    return input().split()
# a, b = get_int_multi()
def get_int_multi():
    return map(int, input().split())
# a_list = get_string_char_list()
def get_string_char_list():
    return list(str(input()))
# print("{} {}".format(a, b))
# for num in range(0, a):
# a_list[idx]
# a_list = [0] * a
'''
while (idx < n) and ():

    idx += 1
'''

def main():

    a, b, c, x, y = get_int_multi()
    ans = 100000 * 5000 * 2

    for i in range(0,x+1):

        for ii in (max(0,(x - i) * 2), max(0,(y - i) * 2, (x - i) * 2)):
            price = i * a

            price += ii * c
            cnt_b = max(0, y - (ii // 2))
            price += cnt_b * b
            ans = min(ans, price)

    print(ans)

if __name__ == '__main__':
    main()


