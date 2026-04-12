from functools import reduce
n = int(input())
S = [list(input()) for _ in range(n)]
chars = sorted(list(reduce(lambda x, y: x & y, [set(s) for s in S])))
nums = [{c: s.count(c) for c in chars} for s in S]
for c in chars:
    c_num = min([num[c] for num in nums])
    print(c * c_num, end="")
print()
