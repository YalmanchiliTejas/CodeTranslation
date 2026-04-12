import math
import itertools

# 与えられた数値の桁数と桁値の総和を計算する.
def calc_digit_sum(num):
    digits = sums = 0
    while num > 0:
        digits += 1
        sums += num % 10
        num //= 10
    return digits, sums


graph = [[] for _ in range(8)]
n, m = map(int, input().split())
for route in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)


answer = 0
routes = [c for c in itertools.permutations(range(0, n), n) if c[0] == 0]
for route in routes:
    seen = set()

    is_one_stroke = True
    for index in range(len(route) - 1):
        node = route[index]

        seen.add(node)
        next_node = route[index+1]
        if not graph[node] or next_node not in graph[node] or next_node in seen:
            is_one_stroke = False
            break

    if is_one_stroke:
        answer += 1

print(answer)