import bisect

N = input()
N = int(N)
S = [-int(input()) for _ in range(N)]
result = []

for i in range(N):
    hoge = bisect.bisect(result,S[i])
    if hoge == len(result):
        result.append(S[i])
    else:
        result[hoge] = S[i]
print(len(result))