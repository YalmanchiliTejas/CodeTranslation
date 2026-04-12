nlist = list(map(int, str(input())))
k = int(input())

helper = {}


def fun(digit, remaining_non_zero, edge_case):
    if str(digit)+ ',' + str(remaining_non_zero)+ ',' + str(edge_case) in helper.keys():
        return helper[str(digit)+ ',' + str(remaining_non_zero)+ ',' + str(edge_case)]

    if remaining_non_zero < 0:
        return 0
    if digit == 0 and remaining_non_zero == 0:
        return 1
    if digit == 0 and remaining_non_zero >= 1:
        return 0

    if edge_case == True:
        ans = 0
        for i in range(nlist[len(nlist) - digit] + 1):
            if i == 0:
                if nlist[len(nlist) - digit] == 0:
                    ans += fun(digit - 1, remaining_non_zero, True)
                else:
                    ans += fun(digit - 1, remaining_non_zero, False)
            elif i == nlist[len(nlist) - digit]:
                ans += fun(digit - 1, remaining_non_zero - 1, True)
            else:
                ans += fun(digit - 1, remaining_non_zero - 1, False)
        helper[str(digit)+ ',' + str(remaining_non_zero)+ ',' + str(edge_case)] = ans
        return ans
    if edge_case == False:
        ans = 0
        for i in range(10):
            if i == 0:
                ans += fun(digit - 1, remaining_non_zero, False)
            else:
                ans += fun(digit - 1, remaining_non_zero - 1, False)
        helper[str(digit)+ ',' + str(remaining_non_zero)+ ',' + str(edge_case)] = ans
        return ans

print(fun(len(nlist), k, True))