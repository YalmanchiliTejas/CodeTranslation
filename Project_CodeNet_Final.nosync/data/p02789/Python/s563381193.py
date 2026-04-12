'''
条件に合うものを絞り込む
data = [1, 2, 3]
s = [x for x in data if x % 3 == 0]
'''
'''
文字配列を数値に
l_si = ['-10', '0', '100']

l_si_i = [int(s) for s in l_si]
'''
'''
a = [2, 4, 6, 8]
b = [3, 6, 9]

print(list(set(a) | set(b)))  # 和集合
print(list(set(a) & set(b)))  # 積集合
'''
'''
N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
count = 0
while len([x for x in A if x % 2 == 0]) == N:
    A = list(map(lambda y: y / 2, A))
    count += 1
print(count)
'''
'''
.append(要素)
.extend(要素)
.insert(場所,要素)
del 配列名[場所]
-1で末尾で末尾から一つ前
'''
'''
間に空白追加
' '.join(lis)
'''
'''
copy.copy(配列名)
'''
'''
sort()
sorted(reverse=true)
'''
'''
2分探索
bisect.bisect_left(リスト, 要素)
'''
'''
リスト同士の演算
list(map(lambda x, y: x+y, el2, el3))
'''
'''
配列の初期化
配列名=[a]*n+[b]*m
'''
'''
重複
list(set())
２次元配列
list(map(list, set(map(tuple, addition))))
'''
'''
順列
for el in itertools.permutations(配列のパターン):
'''
'''
Decimal()
'''
# 入力 =stdin.readline().rstrip()
# 分割 = stdin.readline().rstrip().split()




from sys import stdin
from itertools import accumulate, dropwhile, takewhile, groupby
import bisect
import copy
import math
import itertools
from functools import reduce
from operator import mul
def gcd(*numbers):
    return reduce(math.gcd, numbers)


def gcd_list(numbers):
    return reduce(math.gcd, numbers)


def lcm_base(x, y):
    return (x * y) // math.gcd(x, y)


def lcm(*numbers):
    return reduce(lcm_base, numbers, 1)


def lcm_list(numbers):
    return reduce(lcm_base, numbers, 1)


def get_unique_list(seq):
    seen = []
    return [x for x in seq if x not in seen and not seen.append(x)]


d = stdin.readline().rstrip().split()
a = d[0]
b = d[1]
if a != b:
    print('No')
else:
    print('Yes')
