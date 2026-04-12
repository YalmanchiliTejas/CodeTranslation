from collections import Counter
N = int(input())

C = Counter(input())  # 最初の文字を入力

for _ in range(N - 1):
    Ctmp = Counter(input())
    for k, v in C.items():
        if k in Ctmp:
            C[k] = min(C[k], Ctmp[k])
        else:
            C[k] = 0


ans = []
for k, v in C.items():
    ans.extend([k]*v)
ans.sort()

print("".join(ans))
