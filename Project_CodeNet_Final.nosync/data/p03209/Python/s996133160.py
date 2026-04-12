n, x = map(int, input().split())

a_list = [0]*(n+1)
a_list[0] = 1
p_list = [0]*(n+1)
p_list[0] = 1
for i in range(1, n+1):
    a_list[i] = 2 * a_list[i-1] + 3
    p_list[i] = 2 * p_list[i-1] + 1


def Recursive_function(n, x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x <= a_list[n-1] + 1:
        return Recursive_function(n - 1, x - 1)
    elif x == a_list[n-1] + 2:
        return p_list[n-1] + 1
    elif x == 2 * a_list[n-1] + 3:
        return 2 * p_list[n-1] + 1
    else:
        return p_list[n-1] + 1 + Recursive_function(n-1, x - 2 - a_list[n-1])


print(Recursive_function(n, x))