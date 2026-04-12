import math
import string


def readints():
    return list(map(int, input().split()))


def nCr(n, r):
    return math.factorial(n)//(math.factorial(n-r)*math.factorial(r))


def has_duplicates2(seq):  # リストに重複した要素があるか判定（要素にリストがある場合）
    seen = []
    for item in seq:
        if not(item in seen):
            seen.append(item)
    return len(seq) != len(seen)


def divisor(n):
    divisor = []
    for i in range(1, n+1):
        if n % i == 0:
            divisor.append(i)
    return divisor


# s = input()
# n = len(s)
# m = int(s)


# def check(l):
#     x = int("".join(list(map(str, l))))
#     return m >= x and (3 in l) and (5 in l) and (7 in l)


# def solve(l):
#     if len(l) == n:
#         if check(l):
#             # print(int("".join(list(map(str, l)))))
#             return 1
#         else:
#             return 0
#     a = solve(l+[3])
#     b = solve(l+[5])
#     c = solve(l+[7])
#     d = 0
#     if len(l) == 0 or l[-1] == 0:
#         d = solve(l+[0])
#     return a+b+c+d


# print(solve([]))

#n = readints()[0]
#
#ans = 0
#
# for i in range(n+1):
#    s = list(str(i))
#    a = s.count("3")
#    b = s.count("5")
#    c = s.count("7")
#    if a != 0 and b != 0 and c != 0 and a+b+c == len(s):
#        ans += 1
# print(ans)

s = input()

if (s[0] == 'A' and s[1] == 'A' and s[2] == 'A'):
    print("No")
    exit()
if (s[0] == 'B' and s[1] == 'B' and s[2] == 'B'):
    print("No")
    exit()

print("Yes")
