import sys
input = sys.stdin.readline
n = int(input())
a = [int(input()) for _ in range(n)]
memo = []
ans = 0

def reverse_binary_serch(target, query):
    l = 0
    r = len(target) - 1
    while True:
        if r - l < 2:
            if target[l] < query:
                return l
            else:
                return r
        i = (l + r) // 2
        if target[i] >= query:
            l = i
        else:
            r = i

for ai in a:
    if not memo or memo[-1] >= ai:
        memo.append(ai)
    else:
        index = reverse_binary_serch(memo, ai)
        memo[index] = ai

print(len(memo))
