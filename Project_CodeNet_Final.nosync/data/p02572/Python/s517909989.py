import itertools
import numba
from numba import jit, i8
import decimal


def calc(x):
    return (x % (10 ** 9 + 7))


# map(lambda x: border(int(x)),

n = int(input())
#a = list(map(lambda x: calc(int(x)), input().split()))
a = list(map(int, input().split()))
rev_a = a[::-1]
#print(rev_a, 'rev')
acc_a = list(itertools.accumulate(rev_a))


MOD = 10**9 + 7
ans = 0
num = len(a)
# print(acc_a)

for i, val in enumerate(a):
    if (i == num - 1):
        break
    #temp = sum(a[i + 1:]) % MOD
    temp = acc_a[num - 1 - i - 1] % MOD
    # print(temp)
    # print(temp)
    # temp = val * sum(a[i + 1:])
    # ans += temp % MOD
    ans += (temp * val) % MOD

print(ans % MOD)

'''
@jit
def calc(lis):
    ans = 0
    num = len(lis)
    for i in range(num):
        for j in range(i + 1, num):
            temp = (lis[i] * lis[j]) % MOD
            ans += temp

    return ans


aa = calc(a)
print(aa)
'''

'''
for i in itertools.combinations(a, 2):
    temp = (i[0] * i[1]) % MOD
    ans += temp

print(ans)
'''
