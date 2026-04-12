N = int(input())
Hs = list(map(int, input().split()))

"""
SEA H_1 H_2 H_3 H_4 ... H_N
"""

# 0 ~ i番目の旅館のうち最も高いもの
# max(Hs[0:i+1])

ret = 0
for i in range(N):
    if Hs[i] == max(Hs[0:i+1]):
        ret += 1

print(ret)