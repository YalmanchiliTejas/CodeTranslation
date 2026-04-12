# B - Great Ocean View
# https://atcoder.jp/contests/abc124/tasks/abc124_b

N = int(input())
H = map(int, raw_input().split())
max_h = -1
num_inns = 0

for h in H:
    if h >= max_h:
        num_inns += 1
        max_h = h

print '{}'.format(num_inns)
