"""
P
1
B|P|P|P|B
0|1|1|1|0 3
B|BPPPB|P|BPPPB|B
0|3|1|3|0 7
a_1 = 1
a_n+1 = 2 * a_n + 3
b = 2b + 3 => b = -3
a_n + 3 = 4*2^(n-1)
a_n = 2^(n+2) - 3

b_1 = 1
b_n+1 = b_n * 2 + 1
c = 2c + 1 => c = -1
b_n + 1 = 2^n
b_n = 2^(n+1) - 1
"""


def check(n, x):
    if n == 0:
        return 0
    
    lower_n = 2 ** (n+1) - 3
    lower_pat = 2 ** n - 1
    if x == 1:
        return 0
    elif x == 1 + lower_n:
        return lower_pat
    elif x == 1 + lower_n + 1:
        return lower_pat + 1
    elif x == 1 + lower_n + 1 + lower_n:
        return lower_pat + 1 + lower_pat
    elif x == 1 + lower_n + 1 + lower_n + 1:
        return lower_pat + 1 + lower_pat
    elif 1 < x < 1 + lower_n:
        return check(n-1, x-1)
    elif 1 + lower_n + 1 <x< 1 + lower_n + 1 + lower_n:
        return lower_pat + 1 + check(n-1, x-1-lower_n-1)

N, X = [int(s) for s in input().split()]
print(check(N, X))